#include "show_slide_com.hpp"
#include "controller.hpp"
#include "ostream_wrapper.hpp"
#include "icanvas.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <fstream>

using namespace cli;

ShowSlideCom::ShowSlideCom(const CommandInfo& com) :
                _sem_analizer()
{ 
    _sem_analizer.process_args(com._arguments);
};

void ShowSlideCom::execute()
{
    if (_sem_analizer.get_args().find("-i") == _sem_analizer.get_args().end())
        std::runtime_error("CLI: enter valid index for slide.");

    int index = std::get<int>(_sem_analizer.get_args()["-i"]);
    std::string type = (_sem_analizer.get_args().find("-t") != _sem_analizer.get_args().end()) ? std::get<std::string>(_sem_analizer.get_args()["-t"]) : "cmd";
    std::string path = (_sem_analizer.get_args().find("-p") != _sem_analizer.get_args().end()) ? std::get<std::string>(_sem_analizer.get_args()["-p"]) : "../out.txt";

    
    if (type == "cmd")
    {
        std::shared_ptr<core::ICanvas> canvas = std::make_shared<core::OstreamWrapper>(std::cout);
        core::Controller::instance()->get_vizualizer()->process_slide(canvas, index);
    }
    else if (type == "file")
    {
        if (path.find(".png"))//TODO 
        {
            core::Controller::instance()->get_guicontroller()->save_img(path);
        }
        else 
        {            
            std::ofstream outfile;
            outfile.open(path, std::ios::out | std::ios::trunc);
            if (outfile.is_open())
            {
                std::shared_ptr<core::ICanvas> canvas = std::make_shared<core::OstreamWrapper>(outfile);
                core::Controller::instance()->get_vizualizer()->process_slide(canvas, index);
            }
            else 
                throw std::runtime_error("cant open file");
        }
    }
};

