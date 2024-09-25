#include "add_shape_command.hpp"
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace cli;

AddShapeCommand::AddShapeCommand()
{
    register_options();
}

void AddShapeCommand::execute(const std::vector<std::string>& tokens)
{
    for (int i = 0; i < tokens.size(); ++i)
    {
        if (_options.find(tokens[0]) != _options.end())
        {
            std::vector<std::string> args(tokens.begin() + 1, tokens.end());
            _options[tokens[0]](args);
        } else 
        {
            std::cout << "CLI: SHAPE NOT FOUND:"<< tokens[0] << std::endl;
        }
    }
};

void AddShapeCommand::register_options()
{
    _options["rect"] = [this](const std::vector<std::string>& args){
        this->add_rect(args); 
    };
    _options["circle"] = [this](const std::vector<std::string>& args){
        this->add_circle(args); 
    };
};

void AddShapeCommand::add_rect(const std::vector<std::string>& tokens)
{
    if (tokens.size() % 2 != 0)
        throw std::runtime_error("CLI: WRONG QUANTITY AEGUMENTS:");
    for (size_t i = 0; i < tokens.size(); i += 2)
    {
        _args[tokens[i]] = tokens.at(i + 1);
    }
};

void AddShapeCommand::add_circle(const std::vector<std::string>& tokens)
{
    for (size_t i = 0; i < tokens.size(); i += 2)
    {
        _args[tokens[i]] = tokens.at(i + 1);
    }
};
