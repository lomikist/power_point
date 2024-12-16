#include "add_item_com.hpp"
#include "add_item_action.hpp"
#include "editor.hpp"
#include "item.hpp"
#include "parser.hpp"
#include <algorithm>
#include <cctype>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <variant>

using namespace cli;

AddItemCom::AddItemCom()
{
    register_options();  
};

void AddItemCom::register_options()
{
    _options["-t"] = [this](const std::string& option, const std::string& value){add_type(option, value);};
    _options["-i"] = [this](const std::string& option, const std::string& value){add_index(option, value);};
    _options["-x"] = [this](const std::string& option, const std::string& value){add_x(option, value);};
    _options["-y"] = [this](const std::string& option, const std::string& value){add_y(option, value);};
    _options["-h"] = [this](const std::string& option, const std::string& value){add_h(option, value);};
    _options["-w"] = [this](const std::string& option, const std::string& value){add_w(option, value);};
    _options["-r"] = [this](const std::string& option, const std::string& value){add_radius(option, value);};
    _options["-c"] = [this](const std::string& option, const std::string& value){add_color(option, value);};
    _options["-content"] = [this](const std::string& option, const std::string& value){add_content(option, value);};

    _valid_shape_atributes["rect"]      = {"-c", "-i", "-t"};
    _valid_shape_atributes["textbox"]   = {"-c", "-i", "-t","-content"};
    _valid_shape_atributes["elipse"]    = {"-c", "-i", "-t" };

    _valid_geometry = {"-x", "-y", "-w", "-h"};
};

void AddItemCom::add_x(const std::string& opt, const std::string& value)
{
    int x = Parser::str_to_int(value);
    _geometery[opt] = x;
};
 
void AddItemCom::add_y(const std::string& opt, const std::string& value)
{
    int y = Parser::str_to_int(value);
    _geometery[opt] = y;
};

void AddItemCom::add_w(const std::string& opt, const std::string& value)
{
    int w = Parser::str_to_int(value);
    _geometery[opt] = w;
};

void AddItemCom::add_h(const std::string& opt, const std::string& value)
{
    int h = Parser::str_to_int(value);
    _geometery[opt] = h;
};

void AddItemCom::add_type(const std::string& opt, const std::string& type)
{
    if (_valid_shape_atributes.count(type) == 1) 
    {
        _atributes[opt] = type;
    } else 
    {
        throw std::runtime_error("CLI: No valid shape.");
    }
};

void AddItemCom::add_color(const std::string& opt, const std::string& arg)
{
    if (std::all_of(arg.begin(), arg.end(), ::isalpha))
        _atributes[opt] = arg;
    else
    {
        std::vector<std::string> str_colors = Parser::splitString(arg, ',');
        int r = Parser::str_to_int(str_colors[0]);
        int b = Parser::str_to_int(str_colors[1]);
        int g = Parser::str_to_int(str_colors[2]);
        model::RGB color(r, b, g);
        _atributes[opt] = color;
    }
};

//TODO chane drawing and prinitin part

void AddItemCom::add_content(const std::string& opt, const std::string& args)
{
    _atributes[opt] = args;
};

void AddItemCom::add_index(const std::string& opt, const std::string& args)
{
    int index = Parser::str_to_int(args);
    _atributes[opt] = index;
};

void AddItemCom::add_radius(const std::string& opt, const std::string& args)
{
    int radius = Parser::str_to_int(args);
    _atributes[opt] = radius;
};

bool AddItemCom::if_not_contain(std::vector<std::string> valid_options, model::Atributes current_options)
{
    if (
        std::any_of(
            valid_options.begin(),
            valid_options.end(),
            [valid_options, current_options](auto&& valid_option)
            {
                return std::find_if(
                    current_options.begin(),
                    current_options.end(),
                         [valid_option](auto&& option_pair){
                                   return option_pair.first == valid_option;
                           }
                    ) == current_options.end(); 
            })
    )
        return true;
    else 
        return false;
};

void AddItemCom::execute()
{
    std::string type = std::get<std::string>(_atributes.at("-t"));
    int slide_index = std::get<int>(_atributes.at("-i"));
    int x = std::get<int>(_geometery.at("-x"));
    int y = std::get<int>(_geometery.at("-y"));
    int w = std::get<int>(_geometery.at("-w"));
    int h = std::get<int>(_geometery.at("-h"));
     
    if (if_not_contain(_valid_shape_atributes[type], _atributes))
        throw std::runtime_error("Cli: some atrubutes not setted look documentation.");
    else if (if_not_contain(_valid_geometry, _geometery)) 
        throw std::runtime_error("Cli: some geometery element not setted look documentation.");

    auto action = std::make_shared<core::AddItemAction>(
        std::make_shared<model::Item>(x, y, w, h, _atributes),
            slide_index
        );
    
    core::Editor& editor = core::Editor::get_instance();
    editor.process_action(action);
};

