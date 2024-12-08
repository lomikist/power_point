#include "run_com.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
/*#include "controller.hpp"*/
/*#include "editor.hpp"*/
#include <fstream>

using namespace cli;

RunCom::RunCom()
{
    register_options();
}

void RunCom::execute()
{
    /*if (_args.find("-p") == _args.end())*/
    /*    throw std::runtime_error("CLI: Enter a valid path with -p");*/
    /**/
    /*std::ifstream myfile;*/
    /*myfile.open (std::get<std::string>(_args["-p"]), std::ios::in);*/
    /*if (myfile.is_open())*/
    /*{*/
    /*    while (myfile.good()) */
    /*    {*/
    /*        auto cmd = core::Controller::get_instance().get_parser().parse(myfile);*/
    /*        if (cmd)*/
    /*            cmd->execute(); */
    /*    }*/
    /*}*/
    /*else */
    /*    std::cout << "cant open file\n";*/
};

void RunCom::process_args(const std::vector<std::string>& tokens)
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

void RunCom::register_options()
{
    _options["-p"] = [this](const std::string& arg)
    {
        add_path(arg); 
    };
};

void RunCom::add_path(const std::string& path)
{
    _args["-p"] = path; 
};


