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
        _sem_analizer()
{
    _sem_analizer.process_args(com._arguments);
}

void RunCom::execute()
{
    if (_sem_analizer.get_args().find("-p") == _sem_analizer.get_args().end())
        throw std::runtime_error("CLI: Enter a valid path with -p");

    std::ifstream myfile;
    myfile.open (std::get<std::string>(_sem_analizer.get_args()["-p"]), std::ios::in);
    if (myfile.is_open())
    {
        while (myfile.good()) 
        {
            auto cmd = core::Controller::instance()->get_parser().parse(myfile);
            if (cmd)
                cmd->execute(); 
        }
    }
    else 
        std::cout << "cant open file\n";
    myfile.close();
};


