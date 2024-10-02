#include "show_slide_com.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace cli;

ShowSlideCom::ShowSlideCom()
{
    register_options();  
};
void ShowSlideCom::register_options()
{
    _options["-i"] = [this](const std::vector<std::string>& args)
    {
        add_index(args);
    };
};

void ShowSlideCom::execute(const std::vector<std::string>& tokens)
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

void ShowSlideCom::add_index(const std::vector<std::string>& args)
{
    _args_to_pass["-i"] = args.at(1);
}

