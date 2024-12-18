#include "show_slide_com.hpp"
#include "controller.hpp"
#include "gui_wrapper.hpp"
#include "ostream_wrapper.hpp"
#include "vizualize.hpp"
#include "icanvas.hpp"
#include "parser.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

using namespace cli;

ShowSlideCom::ShowSlideCom()
{
    register_options();  
};

void ShowSlideCom::register_options()
{
    _options["-i"] = [this](const std::string& opt,const std::string& args)
    {
        add_index(opt, args);
    };
    _options["-t"] = [this](const std::string& opt,const std::string& args)
    {
        add_type(opt, args);
    };
    _options["-p"] = [this](const std::string& opt,const std::string& args)
    {
        add_path(opt, args);
    };
};

void ShowSlideCom::add_index(const std::string& opt,const std::string& arg)
{
    int index = cli::Parser::str_to_int(arg); 
    _args[opt] = index;
}

void ShowSlideCom::add_type(const std::string& opt,const std::string& arg)
{
    _args[opt] = arg;
}

void ShowSlideCom::add_path(const std::string& opt,const std::string& arg)
{
    _args[opt] = arg;
}

void ShowSlideCom::execute()
{
    if (_args.find("-i") == _args.end())
        std::runtime_error("CLI: enter valid index for slide.");

    int index = std::get<int>(_args["-i"]);
    std::string type = (_args.find("-t") != _args.end()) ? std::get<std::string>(_args["-t"]) : "cmd";
    std::string path = (_args.find("-p") != _args.end()) ? std::get<std::string>(_args["-p"]) : "../out.txt";

    core::Vizualizer& vizualizer = core::Vizualizer::get_instance();
    if (type == "cmd")
    {
        std::shared_ptr<core::ICanvas> canvas = std::make_shared<core::OstreamWrapper>(std::cout);
        vizualizer.process_slide(canvas, index);
    }
    else if (type == "file")
    {
        if (path.find(".png"))//TODO 
        {
            core::Controller::get_instance().get_guicontroller()->save_img(path);
        }
        else 
        {            
            std::ofstream outfile;
            outfile.open(path, std::ios::out | std::ios::trunc);
            if (outfile.is_open())
            {
                std::shared_ptr<core::ICanvas> canvas = std::make_shared<core::OstreamWrapper>(outfile);
                vizualizer.process_slide(canvas, index);
            }
            else 
                throw std::runtime_error("cant open file");
        }
    }
};

