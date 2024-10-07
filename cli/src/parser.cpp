#include "parser.hpp"
#include "add_slide_com.hpp"
#include "add_shape_com.hpp"
#include "show_slide_com.hpp"
#include "icommand.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <istream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
using namespace cli;

Parser::Parser()
{
    _command_creator.register_func("add", "<slide>", [](){
        return std::make_shared<AddSlideCom>();
    });
    _command_creator.register_func("add", "<shape>", [](){
        return std::make_shared<AddShapeCom>();
    });
    _command_creator.register_func("show", "<slide>", [](){
        return std::make_shared<ShowSlideCom>();
    });

};

Parser::~Parser()
{
};

std::shared_ptr<ICommand> Parser::parse(std::istream& is)
{
    std::string str;

    while (std::getline(is, str))
    {
        _str_tokens.clear();
        _tokens.clear();
        try { 
            tokenize(str); 
            validate_tokens();
            auto cmd = validate_semantics(); 
            if (cmd)
                return cmd;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return nullptr;
};

std::vector<TokenType> Parser::tokenize(const std::string& str)
{
    _str_tokens = split(str, ' ');
    for (auto&& str : _str_tokens)
    {
        _tokens.push_back(get_token_type(str)); 
    }
    return _tokens;
};

std::shared_ptr<ICommand> Parser::validate_semantics()
{
    std::shared_ptr<ICommand>   cmd;
    std::vector<std::string>    argumens;

    if (_tokens[1] == TokenType::SUBCOM)
    {
        cmd = _command_creator.create(_str_tokens[0], _str_tokens[1]);
        argumens.assign(_str_tokens.begin() + 2, _str_tokens.end());
    } else {
        cmd = _command_creator.create(_str_tokens[0]);
        argumens.assign(_str_tokens.begin() + 1, _str_tokens.end());
    }
    if (cmd)
    {
        cmd->process_args(argumens);
        return cmd;
    } else 
        throw std::runtime_error("CLI: COMMAND " + _str_tokens[0] + " NOT FOUND");
};

void Parser::validate_tokens()
{
    if (_tokens[0] != TokenType::WORD)
        std::runtime_error("CLI: NOT VALID COMMAND");
    for (int i = 0; i < _tokens.size() - 1; ++i)
    {
        switch (_tokens[i])
        {
            case TokenType::WORD:
                if (_tokens[i + 1] == TokenType::WORD ||
                    _tokens[i + 1] == TokenType::NUMBER)
                    throw std::runtime_error("CLI: INVALID OPTION OR SUBCOM");
            break;

            case TokenType::SUBCOM:
                if (_tokens[i + 1] == TokenType::WORD ||
                    _tokens[i + 1] == TokenType::NUMBER ||
                    _tokens[i + 1] == TokenType::SUBCOM )
                    throw std::runtime_error("CLI: INVALID OPTION");
            break;

            case TokenType::ARGUMENT:
                if (_tokens[i + 1] == TokenType::SUBCOM ||
                    _tokens[i + 1] == TokenType::ARGUMENT)
                    throw std::runtime_error("CLI: INVALID Value");
            break;

            case TokenType::NUMBER:
                if (_tokens[i + 1] == TokenType::SUBCOM ||
                    _tokens[i + 1] == TokenType::WORD ||
                    _tokens[i + 1] == TokenType::NUMBER)
                    throw std::runtime_error("CLI: INVALID OPTION OR ");
            break;

            case TokenType::BADTYPE:
                std::runtime_error("CLI: BADTYPE");
            break;
        } 
    }
};

TokenType Parser::get_token_type(const std::string& token)
{
    if (std::all_of(token.begin(), token.end(), ::isdigit))
        return TokenType::NUMBER;

    if (token[0] == '-')
    {
        if (std::all_of(token.begin() + 1, token.end(), ::isdigit))
            return TokenType::NUMBER;
        
        if (!std::all_of(token.begin() + 1, token.end(), ::isalpha))
            throw std::runtime_error("CLI: NOT VALID OPTION");

        return TokenType::ARGUMENT;
    }
    else if (token[0] == '<' &&
            token[token.size() - 1] == '>' &&
            std::all_of(token.begin() + 1, token.end() - 1, ::isalpha))
    {
        return TokenType::SUBCOM;
    }
    else if (std::all_of(token.begin(), token.end(), ::isalpha)) {
        return TokenType::WORD;
    }
    else {
        return TokenType::BADTYPE;
    }
};

std::vector<std::string> Parser::split(const std::string& input, char delimiter)
{
    std::vector<std::string> result; 
    size_t start = 0;
    size_t end = input.find(delimiter);

    while (end != std::string::npos)
    {
        result.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(delimiter, start);
    } 
    result.push_back(input.substr(start));
    //remove empty lines
    result.erase(
        std::remove_if(
            result.begin(),
            result.end(),
            [](const std::string& str){ return str.empty();}
        ),
        result.end()
    );
    return result;
}

int Parser::str_to_int(const std::string& str) {
    // Check if the entire string is numeric (optional support for negative sign)
    if (str.empty() || (!std::all_of(str.begin(), str.end(), ::isdigit) && 
        !(str[0] == '-' && std::all_of(str.begin() + 1, str.end(), ::isdigit)))) {
        throw std::runtime_error("CORE: Can't convert" + str + " to int.");
    }
    return std::stoi(str);
}
