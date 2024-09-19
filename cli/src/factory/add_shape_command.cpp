#include "add_shape_command.hpp"
#include <functional>
#include <iostream>
#include <string>
#include <vector>


AddShapeCommand::AddShapeCommand()
{
    register_options();
}

void AddShapeCommand::execute(const std::vector<std::string>& tokens)
{
    for (int i = 0; i < tokens.size(); ++i)
    {
        if (_opotions.find(tokens[0]) != _opotions.end())
        {
            std::vector<std::string> args(tokens.begin() + 1, tokens.end());
            _opotions[tokens[0]](args);
        } else 
        {
            std::cout << "SHAPE NOT FOUND: "<< tokens[0] << std::endl;
        }
    }
};

void AddShapeCommand::register_options()
{
    _opotions["rect"] = [this](const std::vector<std::string>& args){
        this->add_rect(args); 
    };
    _opotions["circle"] = [this](const std::vector<std::string>& args){
        this->add_circle(args); 
    };
};

void AddShapeCommand::add_rect(const std::vector<std::string>& tokens)
{
    std::cout << "add_rect" << std::endl;    
};

void AddShapeCommand::add_circle(const std::vector<std::string>& tokens)
{
    std::cout << "add_circle" << std::endl;    
};
