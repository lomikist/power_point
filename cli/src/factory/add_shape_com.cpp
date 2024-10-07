#include "add_shape_com.hpp"
#include "editor.hpp"
#include "parser.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <variant>

using namespace cli;

AddShapeCom::AddShapeCom()
{
    register_options();  
};

void AddShapeCom::register_options()
{
    _options["-t"] = [this](const std::string& args){add_type(args);};
    _options["-i"] = [this](const std::string& args){add_index(args);};
    _options["-x"] = [this](const std::string& args){add_x(args);};
    _options["-y"] = [this](const std::string& args){add_y(args);};
    _options["-h"] = [this](const std::string& args){add_h(args);};
    _options["-w"] = [this](const std::string& args){add_w(args);};
    _options["-c"] = [this](const std::string& args){add_color(args);};
};

void AddShapeCom::process_args(const std::vector<std::string>& tokens)
{
    for (int i = 0; i < tokens.size(); ++i)
    {
        if (_options.find(tokens[i]) != _options.end())
        {
            std::vector<std::string> args(tokens.begin() + i, tokens.end());
            _options[tokens[i]](tokens[i + 1]);
            i++;
        } else 
        {
            throw std::runtime_error("CLI: OPTION NOT FOUND:" + tokens[i]);
        }
    }    
};

void AddShapeCom::add_x(const std::string& args)
{
    int x = Parser::str_to_int(args);
    _args["-x"] = x;
};

void AddShapeCom::add_y(const std::string& args)
{
    int y = Parser::str_to_int(args);
    _args["-y"] = y;
};

void AddShapeCom::add_type(const std::string& args)
{
    _args["-t"] = args;
};

void AddShapeCom::add_h(const std::string& args)
{
    int h = Parser::str_to_int(args);
    _args["-h"] = h;
};

void AddShapeCom::add_w(const std::string& args)
{
    int w = Parser::str_to_int(args);
    _args["-w"] = w;
};

void AddShapeCom::add_color(const std::string& args)
{
    _args["-c"] = args;
};

void AddShapeCom::add_index(const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args["-i"] = index;
};

void AddShapeCom::execute()
{   
    core::Editor& editor = core::Editor::get_instance();
    editor.add_shape(_args);
};









