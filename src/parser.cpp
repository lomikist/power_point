#include "../inc/parser.hpp"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

struct Indexes
{
    int com_index = -1;
    int subcom_index = -1;
    int option_index = -1;
    int argument_index = -1;
};

void Parser::start()
{
    while (true)
    {
        std::getline(std::cin, _current);
        tokenize(_current);
    } 
}

void Parser::tokenize(std::string user_input)
{
    _pipe_tokens = split(user_input, '|');
    _tokens = split(_pipe_tokens[0], ' ');
    Indexes indexes;
    for (auto&& token : _tokens)
    {
        if (indexes.com_index == -1)
        { 
            auto iterator = std::find(_commands.begin(), _commands.end(), token);
            if (iterator != _commands.end())
            {
                indexes.com_index = iterator - _commands.begin();
            }
        }
        else if (indexes.subcom_index == -1)
        {
            subcommand_check(token, indexes);
        }
        else if (indexes.option_index == -1)
        {
            option_check(token, indexes);
        }
        else if (indexes.argument_index == -1) 
        {
            argument_check(token, indexes);
        }
    }
    std::cout   << "command index - " << indexes.com_index \
                << "\nsubcomand index - "<<  indexes.subcom_index \
                << "\noptions index - " << indexes.option_index <<  std::endl;  
    if (indexes.subcom_index != -1 && indexes.option_index != -1) {
        std::cout << "this options is right, and arguments\n";
    }
}

bool isNumber(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

void Parser::argument_check(const std::string &token, Indexes& indexes)
{
    indexes.argument_index = 1;// TODO for now 
    for (int i = 3; i < _tokens.size(); i++)
    {
        auto path = _options[_subcommands[_commands[indexes.com_index]][indexes.subcom_index]][indexes.option_index]; 
        auto iterator = std::find(
                _arguments[path].begin(),
                _arguments[path].end(),
                _tokens[i]);
        if (iterator != _arguments[path].end())
        {
            i++;
            std::cout << _tokens[i] << "\n";
        } else {
            std::cout << "error" << std::endl;
            break;
        }
    }
}

void Parser::option_check(const std::string &token, Indexes& indexes)
{
    auto iterator = std::find(
        _options[_subcommands[_commands[indexes.com_index]][indexes.subcom_index]].begin(),
        _options[_subcommands[_commands[indexes.com_index]][indexes.subcom_index]].end(),
        token
    );
    if (iterator != _options[_subcommands[_commands[indexes.com_index]][indexes.subcom_index]].end()) 
        indexes.option_index = iterator - _options[_subcommands[_commands[indexes.com_index]][indexes.subcom_index]].begin(); 
};

void Parser::subcommand_check(const std::string &token, Indexes& indexes)
{
     auto iterator = std::find(_subcommands[_commands[indexes.com_index]].begin(),
                               _subcommands[_commands[indexes.com_index]].end(),
                               token); 
     if (iterator != _subcommands[_commands[indexes.com_index]].end())
         indexes.subcom_index = iterator - _subcommands[_commands[indexes.com_index]].begin();
}

std::vector<std::string> Parser::split(const std::string& input, char ch)
{
    std::vector<std::string> result; 
    size_t start = 0;
    size_t end = input.find(ch);

    while (end != std::string::npos)
    {
        result.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(ch, start);
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

