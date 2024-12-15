#include "parser.hpp"
#include "add_slide_com.hpp"
#include "add_item_com.hpp"
#include "exit_com.hpp"
#include "remove_slide_com.hpp"
#include "rendo_com.hpp"
#include "undo_com.hpp"
#include "logger.hpp"
#include "show_slide_com.hpp"
#include "run_com.hpp"
#include "icommand.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <istream>
#include <iterator>
#include <memory>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using namespace cli;

Parser::Parser()
{
    command_init();
    create_table();
 };

void Parser::command_init()
{
    _command_creator.register_func("add", "<slide>", [](){
        return std::make_shared<AddSlideCom>();
    });
    _command_creator.register_func("add", "<shape>", [](){
        return std::make_shared<AddItemCom>();
    });
    _command_creator.register_func("show", "<slide>", [](){
        return std::make_shared<ShowSlideCom>();
    });
    _command_creator.register_func("remove", "<slide>", [](){
        return std::make_shared<RemoveSlideCom>();
    });
    _command_creator.register_func("run", "", [](){
        return std::make_shared<RunCom>();
    });
    _command_creator.register_func("exit", "", [](){
        return std::make_shared<ExitCom>();
    });
    _command_creator.register_func("undo", "", [](){
        return std::make_shared<UndoCom>();
    });
    _command_creator.register_func("rendo", "", [](){
        return std::make_shared<RendoCom>();
    });
};

void Parser::create_table()
{
    _valid_states[TokenType::START] = {TokenType::WORD}; 
    _valid_states[TokenType::WORD] = {TokenType::WORD, TokenType::NUM, TokenType::OPT, TokenType::ECON, TokenType::SUBCOM}; 
    _valid_states[TokenType::OPT] = {TokenType::WORD, TokenType::NUM, TokenType::MVAL, TokenType::SCON};  
    _valid_states[TokenType::NUM] = {TokenType::OPT, TokenType::ECON}; 
    _valid_states[TokenType::MVAL] = {TokenType::OPT, TokenType::MVAL}; 
    _valid_states[TokenType::SCON] = {TokenType::WORD, TokenType::NUM, TokenType::ECON}; 
    _valid_states[TokenType::ECON] = {TokenType::OPT}; 
    _valid_states[TokenType::SUBCOM] = {TokenType::OPT}; 
};

void Parser::shape_command(TokenType token, const std::string& raw_token)
{
    if (token == TokenType::ECON) {
        _content_started = false;
        _content += raw_token + " "; 
        _command_info._arguments[_last_option] = _content;
    }
    if (_content_started == true) {
        _content += raw_token + " ";
    }
    else 
    {
        if (_token_order == 0 && _current_state == TokenType::START)
        { 
            _command_info._command_name = raw_token;
        }
        else if (_token_order == 1 &&
            _current_state == TokenType::WORD &&
            token == TokenType::SUBCOM)
        {
            _command_info._subcommand_name = raw_token;
        }
        else if (token == TokenType::OPT)
        {
            _last_option = raw_token;
        }
        else if (token == TokenType::SCON)
        {
            _content_started = true;
            _content += raw_token + " ";
        }
        else if (token == TokenType::WORD || token == TokenType::NUM)
        {
            _command_info._arguments[_last_option] = raw_token;
        }
    }
    _token_order++;
};

Parser::~Parser()
{
};

std::shared_ptr<ICommand> Parser::parse(std::istream& is)
{
    std::string full_str;
    std::getline(is, full_str);
    std::stringstream current_line_stream(full_str); 
    std::string raw_token; 
    try
    {
        while (current_line_stream >> raw_token) {
            TokenType token = _tokenizer.get_token(raw_token);
            if (_valid_states[_current_state].count(token) != 0) {
                shape_command(token, raw_token); 
                _current_state = token;
            }
            else { 
                throw std::runtime_error(std::string("wrong token " + raw_token));
            }
        }
        auto command = _command_creator.create(_command_info._command_name + _command_info._subcommand_name);
        command->process_args(_command_info);

        ////////////////////
        reset();
        ////////////////////

        return command;
    }
    catch (const std::exception& e)
    {
        reset();
        core::Logger::get_instance().notify_loggers(e.what());
    }
    return nullptr;
};

void Parser::reset()
{
    _command_info._arguments.clear();
    _command_info._command_name.clear();
    _command_info._subcommand_name.clear();
    _current_state = TokenType::START;
    _content_started = false;
    _token_order = 0;
    _last_option = "";
    _content = "";
};

TokenType Parser::Tokenizer::get_token(const std::string& token)
{
    if (start_con_check(token)) {
        return TokenType::SCON;
    }
    else if (end_con_check(token)) {
        return TokenType::ECON;
    }
    else if (word_check(token)) {
        return TokenType::WORD;
    }
    else if (opt_check(token)) {
        return TokenType::OPT;
    }   
    else if (num_check(token)) {
        return TokenType::NUM;
    }
    else if (mval_check(token)) {
        return TokenType::MVAL;
    }
    else if (subcom_check(token)) {
        return TokenType::SUBCOM;
    }
    return TokenType::BADTYPE;
};

bool Parser::Tokenizer::start_con_check(const std::string& str)
{
    if (str[0] == '"'
        && std::all_of(str.begin() + 1, str.end(), ::isalnum))
    {
        return true;
    }
    return false;
}  

bool Parser::Tokenizer::end_con_check(const std::string& str)
{
    if (str[str.size() - 1] == '"'
        && std::all_of(str.begin(), str.end() - 1, ::isalnum))
    {
        return true;
    }
    return false;
}  

bool Parser::Tokenizer::subcom_check(const std::string& str)
{
    if (str[0] == '<' &&
        str[str.size() - 1] == '>' && 
        std::all_of(str.begin() + 1, str.end() - 1, ::isalpha))
    {
        return true;
    }
    return false;
};

bool Parser::Tokenizer::word_check(const std::string& str)
{
    if (std::all_of(str.begin(), str.end(), ::isalnum)) {
        return true;
    }
    return false;
}  

bool Parser::Tokenizer::opt_check(const std::string& str)
{
    if (str[0] == '-' && std::all_of(str.begin() + 1, str.end(), ::isalpha))
    {
        return true;
    }
    return false;
}

bool Parser::Tokenizer::num_check(const std::string& str)
{
    if (std::all_of(str.begin(), str.end(), ::isdigit) || 
       (str[0] == '-' && std::all_of(str.begin() + 1, str.end(), ::isdigit))) 
    {
        return true;
    }
    return false;
} 

bool Parser::Tokenizer::mval_check(const std::string& str)
{
    auto first = std::find(str.begin(), str.end(), ',');
    auto second = std::find(first, str.end(), ',');
    auto temp = second;
    auto last_comma = std::find(str.rbegin(), str.rend(), ',');

    if (!std::all_of(str.begin(), first, ::isdigit))
        return false;
    while (second < last_comma.base())
    {
        if (!std::all_of(first + 1, second, ::isdigit))
            return false;
        if (second - first == 1)
            return false;
        second = std::find(second + 1, str.end(), ',');
        first = temp;
        temp = second;
    }
    if (!std::all_of(last_comma.base(), str.end(), ::isdigit))
        return false;
    return true;
};

int Parser::str_to_int(const std::string& str)
{
    if (str.empty() || (!std::all_of(str.begin(), str.end(), ::isdigit) && 
        !(str[0] == '-' && std::all_of(str.begin() + 1, str.end(), ::isdigit)))) {
        throw std::runtime_error("CORE: Can't convert" + str + " to int.");
    }
    return std::stoi(str);
}
