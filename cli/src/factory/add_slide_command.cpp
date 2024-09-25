#include "add_slide_command.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace cli;

AddSlideCommand::AddSlideCommand()
{
    register_options();  
};
void AddSlideCommand::register_options()
{
    _options["-n"] = [this](const std::vector<std::string>& args){
        this->add_title(args); 
    };
    _options["-i"] = [this](const std::vector<std::string>& args)
    {
        this->add_index(args);
    };
};
void AddSlideCommand::execute(const std::vector<std::string>& tokens)
{
    for (int i = 0; i < tokens.size(); ++i)
    {
        if (_options.find(tokens[i]) != _options.end())
        {
            std::vector<std::string> args(tokens.begin() + i, tokens.end());
            _options[tokens[i]](args);
            i++; // for jump over arg value
        } else 
        {
            std::runtime_error("CLI: OPTION NOT FOUND:" + tokens[i]);
        }
    }    
};

void AddSlideCommand::add_title(const std::vector<std::string>& args)
{
    _args["-n"] = args.at(1);
};

void AddSlideCommand::add_index(const std::vector<std::string>& args)
{
    _args["-i"] = args.at(1);
};

