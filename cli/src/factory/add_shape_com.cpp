#include "add_shape_com.hpp"
#include "editor.hpp"
#include "parser.hpp"
#include <algorithm>
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
    _optional_funcs["-t"] = [this](const std::string& args){add_type(args);};
    _optional_funcs["-i"] = [this](const std::string& args){add_index(args);};
    _optional_funcs["-x"] = [this](const std::string& args){add_x(args);};
    _optional_funcs["-y"] = [this](const std::string& args){add_y(args);};
    _optional_funcs["-h"] = [this](const std::string& args){add_h(args);};
    _optional_funcs["-w"] = [this](const std::string& args){add_w(args);};
    _optional_funcs["-r"] = [this](const std::string& args){add_radius(args);};
    _optional_funcs["-c"] = [this](const std::string& args){add_color(args);};

    _valid_shape_atributes["circle"]    = {"-c", "-i", "-t"};
    _valid_shape_atributes["rect"]      = {"-c", "-i", "-t"};
    _valid_shape_atributes["textbox"]   = {"-c", "-i", "-t","-content"};
    _valid_shape_atributes["elipse"]    = {"-c", "-i", "-t" };

    _valid_geometry = {"-x", "-y", "-w", "-h"};
};

void AddShapeCom::process_args(const std::vector<std::string>& tokens)
{
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        if (_optional_funcs.find(tokens[i]) != _optional_funcs.end())
        {
            _optional_funcs[tokens[i]](tokens[i + 1]);
            i++;
        } else 
        {
            throw std::runtime_error("CLI: option not exist: " + tokens[i]);
        }
    }
    std::string type = std::get<std::string>(_atributes["-t"]);

    if (_valid_shape_atributes.count(type) == 1) 
    {
        std::any_of(_atributes.begin(), _atributes.end(), [&](auto&& pair){
            if (std::find(_valid_shape_atributes[type].begin(),
                             _valid_shape_atributes[type].end(),
                             pair.first) == _valid_shape_atributes[type].end()) 
                throw std::runtime_error("CLI: some atributes " + pair.first + " not found.");
            else
                return true;
        });
        std::any_of(_geometery.begin(), _geometery.end(), [this](auto&& pair){
            if (std::find(_valid_geometry.begin(), _valid_geometry.end(), pair.first) == _valid_geometry.end())
                throw std::runtime_error("CLI: some geometry " + pair.first + " option not found.");
            else
                return true;
        });
    }
    else 
{
        throw std::runtime_error("CLI: No valid shape.");
    }

};

void AddShapeCom::add_x(const std::string& args)
{
    int x = Parser::str_to_int(args);
    _geometery["-x"] = x;
};
 
void AddShapeCom::add_y(const std::string& args)
{
    int y = Parser::str_to_int(args);
    _geometery["-y"] = y;
};

void AddShapeCom::add_w(const std::string& args)
{
    int w = Parser::str_to_int(args);
    _geometery["-w"] = w;
};

void AddShapeCom::add_h(const std::string& args)
{
    int h = Parser::str_to_int(args);
    _geometery["-h"] = h;
};

void AddShapeCom::add_type(const std::string& args)
{
    _atributes["-t"] = args;
};

void AddShapeCom::add_color(const std::string& args)
{
    _atributes["-c"] = args;
};

void AddShapeCom::add_index(const std::string& args)
{
    int index = Parser::str_to_int(args);
    _atributes["-i"] = index;
};

void AddShapeCom::add_radius(const std::string& args)
{
    int radius = Parser::str_to_int(args);
    _atributes["-r"] = radius;
};

void AddShapeCom::execute()
{
    core::Editor& editor = core::Editor::get_instance();
    editor.add_item(_geometery, _atributes);
};

