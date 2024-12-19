#include "run_com.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include "controller.hpp"
#include "editor.hpp"
#include "logger.hpp"
#include <fstream>

using namespace cli;

RunCom::RunCom(const CommandInfo& com):
        RunSem()
{
    process_args(com._arguments);
}

void RunCom::execute()
{
    if (_args.find("-p") == _args.end())
        throw std::runtime_error("CLI: Enter a valid path with -p");

    std::ifstream myfile;
    myfile.open (std::get<std::string>(_args["-p"]), std::ios::in);
    if (myfile.is_open())
    {
        while (myfile.good()) 
        {
            auto cmd = core::Controller::get_instance().get_parser().parse(myfile);
            if (cmd)
                cmd->execute(); 
        }
    }
    else 
        std::cout << "cant open file\n";
    myfile.close();
};


