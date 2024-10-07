#include "show_slide_com.hpp"
#include "parser.hpp"
#include "vizualize.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>
using namespace cli;

ShowSlideCom::ShowSlideCom()
{
    register_options();  
};
void ShowSlideCom::register_options()
{
    _options["-i"] = [this](const std::vector<std::string>& args)
    {
        add_index(args[1]);
    };
    _options["-t"] = [this](const std::vector<std::string>& args)
    {
        add_type(args[1]);
    };
};

void ShowSlideCom::execute()
{
    int index = std::get<int>(_args["-i"]);
    std::string type = std::get<std::string>(_args["-t"]);

    std::cout << "showing slide" << index << "\n";

    core::Vizualizer& vizualizer = core::Vizualizer::get_instance();

    if (type == "cmd")
        vizualizer.print(std::cout, index);
    else if (type == "file")
    {
        std::ofstream outfile;
        outfile.open("../out.txt", std::ios::out | std::ios::trunc);
        vizualizer.print(outfile, index);
    }
};

void ShowSlideCom::process_args(const std::vector<std::string>& tokens)
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

void ShowSlideCom::add_index(const std::string& arg)
{
    int index = cli::Parser::str_to_int(arg); 
    _args["-i"] = index;
}

void ShowSlideCom::add_type(const std::string& arg)
{
    _args["-t"] = arg;
}

