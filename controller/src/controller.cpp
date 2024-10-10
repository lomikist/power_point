#include "controller.hpp"
#include "add_shape_com.hpp"
#include "add_slide_com.hpp"
#include "editor.hpp"
#include "show_slide_com.hpp"
#include "icommand.hpp"
#include "rect_shape.hpp"
#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>

using namespace core;

Controller& Controller::get_instance()
{
    static Controller _instance;
    return _instance;
};

cli::Parser& Controller::get_parser()
{
    return *_parser;
};

Controller::Controller()
{
    _parser = std::make_unique<cli::Parser>();
    _model = std::make_shared<model::Model>();
    _editor.set_model(_model);
    _vizualizer.set_model(_model);
}

Controller::~Controller()
{
};

void Controller::start()
{
    while (true)
    {
        try{
            auto cmd = _parser->parse(std::cin);
            if (cmd)
                cmd->execute();
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        };
    }
};

