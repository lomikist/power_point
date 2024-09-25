#include "parser.hpp"
#include "add_shape_command.hpp"
#include "add_slide_command.hpp"
#include "observer.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace cli;

bool isNumber(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
};

Parser::Parser()
{
    _command_creator.register_func("add", "-slide", [](){
        return std::make_shared<AddSlideCommand>();
    });
    _command_creator.register_func("add", "-shape", [](){
        return std::make_shared<AddShapeCommand>();
    });
};

void Parser::start(std::string user_input)
{
    _pipe_tokens = split(user_input, '|');
    _tokens = split(_pipe_tokens[0], ' ');
    if (_tokens.size() > 2)
    {
        auto cmd = _command_creator.create(_tokens[0], _tokens[1]);
        if (cmd)
        {
            std::vector<std::string> args(_tokens.begin() + 2, _tokens.end());
            try {
                cmd->execute(args);
                notify_observers(cmd);
            } catch(std::exception& e) {
                std::cout << e.what() << std::endl; 
            }
        }
        else 
            std::cout << "CLI: INVALID ARGUMENT:" << std::endl;
    }
};

void Parser::notify_observers(const std::shared_ptr<Command>& cmd)
{
    for (auto&& observer : _observers)
    {
        observer->update_cli(cmd);
    } 
};
void Parser::add_observer(std::shared_ptr<cli::Observer> obj)
{
    _observers.push_back(obj); 
};
void Parser::remove_observer(std::shared_ptr<cli::Observer> remove_ob)
{
    _observers.erase(std::remove_if(
        _observers.begin(),
        _observers.end(),
        [&remove_ob](const std::shared_ptr<cli::Observer>& obj){
            return obj == remove_ob;
        }),
        _observers.end());
};

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

