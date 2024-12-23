#include "add_item_sem.hpp"
#include "add_item_com.hpp"
#include "parser.hpp"

using namespace cli;

AddItemSem::AddItemSem()
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
};

cli::Atributes AddItemSem::get_atributes()
{
    return _atributes; 
} 

cli::Atributes AddItemSem::get_geometery()
{
    return _geometery; 
} 

void AddItemSem::add_x(const std::string& opt, const std::string& value)
{
    int x = Parser::str_to_int(value);
    _geometery[opt] = x;
};
 
void AddItemSem::add_y(const std::string& opt, const std::string& value)
{
    int y = Parser::str_to_int(value);
    _geometery[opt] = y;
};

void AddItemSem::add_w(const std::string& opt, const std::string& value)
{
    int w = Parser::str_to_int(value);
    _geometery[opt] = w;
};

void AddItemSem::add_h(const std::string& opt, const std::string& value)
{
    int h = Parser::str_to_int(value);
    _geometery[opt] = h;
};

void AddItemSem::add_type(const std::string& opt, const std::string& type)
{
    if (AddItemCom::s_valid_shape_atributes.count(type) == 1) 
    {
        _atributes[opt] = type;
    } else 
    {
        throw std::runtime_error("CLI: No valid shape.");
    }
};

void AddItemSem::add_color(const std::string& opt, const std::string& arg)
{
    if (std::all_of(arg.begin(), arg.end(), ::isalpha))
        _atributes[opt] = arg;
    else
    {
        std::vector<std::string> str_colors = Parser::splitString(arg, ',');
        int r = Parser::str_to_int(str_colors[0]);
        int b = Parser::str_to_int(str_colors[1]);
        int g = Parser::str_to_int(str_colors[2]);
        cli::RGB color(r, b, g);
        _atributes[opt] = color;
    }
};

void AddItemSem::add_content(const std::string& opt, const std::string& args)
{
    _atributes[opt] = args;
};

void AddItemSem::add_index(const std::string& opt, const std::string& args)
{
    int index = Parser::str_to_int(args);
    _atributes[opt] = index;
};

void AddItemSem::add_radius(const std::string& opt, const std::string& args)
{
    int radius = Parser::str_to_int(args);
    _atributes[opt] = radius;
};

bool AddItemSem::if_not_contain(std::vector<std::string> valid_options, cli::Atributes current_options)
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

