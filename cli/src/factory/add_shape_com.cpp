#include "add_shape_com.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace cli;

AddShapeCom::AddShapeCom()
{
    register_options();  
};
void AddShapeCom::register_options()
{
    _options["-t"] = [this](const std::vector<std::string>& args){add_type(args);};
    _options["-i"] = [this](const std::vector<std::string>& args){add_index(args);};
    _options["-x"] = [this](const std::vector<std::string>& args){add_x(args);};
    _options["-y"] = [this](const std::vector<std::string>& args){add_y(args);};
    _options["-h"] = [this](const std::vector<std::string>& args){add_h(args);};
    _options["-w"] = [this](const std::vector<std::string>& args){add_w(args);};
    _options["-c"] = [this](const std::vector<std::string>& args){add_color(args);};
};

void AddShapeCom::execute(const std::vector<std::string>& tokens)
{
    for (int i = 0; i < tokens.size(); ++i)
    {
        if (_options.find(tokens[i]) != _options.end())
        {
            std::vector<std::string> args(tokens.begin() + i, tokens.end());
            _options[tokens[i]](args);
            i++;
        } else 
        {
            throw std::runtime_error("CLI: OPTION NOT FOUND:" + tokens[i]);
        }
    }    
};

void AddShapeCom::add_x(const std::vector<std::string>& args)
{
    _args_to_pass["-x"] = args.at(1);
};

void AddShapeCom::add_y(const std::vector<std::string>& args)
{
    _args_to_pass["-y"] = args.at(1);
};

void AddShapeCom::add_type(const std::vector<std::string>& args)
{
    _args_to_pass["-t"] = args.at(1);
};

void AddShapeCom::add_h(const std::vector<std::string>& args)
{
    _args_to_pass["-h"] = args.at(1);
};

void AddShapeCom::add_w(const std::vector<std::string>& args)
{
    _args_to_pass["-w"] = args.at(1);
};

void AddShapeCom::add_color(const std::vector<std::string>& args)
{
    _args_to_pass["-c"] = args.at(1);
};

void AddShapeCom::add_index(const std::vector<std::string>& args)
{
    _args_to_pass["-i"] = args.at(1);
};


