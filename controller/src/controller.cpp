#include "controller.hpp"
#include "editor.hpp"
#include "gui_controller.hpp"
#include "icanvas.hpp"
#include "qcoreapplication.h"
#include "qobjectdefs.h"
#include "qpainter.h"
#include "qt_wrapper.hpp"
#include "view.hpp"
#include <ctime>
#include <thread>
#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <QTimer>

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
    _parser         = std::make_unique<cli::Parser>();
    _model          = std::make_shared<model::Model>();
    _gui_controller = std::make_shared<gui::GuiController>();

    _editor.set_model(_model);
    _editor.addObserver(_gui_controller);
    _vizualizer.set_model(_model);

}

Controller::~Controller()
{};

void Controller::process_args()
{
    while (true)
    {
        try
        {
            QCoreApplication::processEvents();
            auto cmd = _parser->parse(std::cin);
            if (cmd)
            {
                cmd->execute();
            }
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        };
    }
};

void Controller::start()
{
    std::thread parser_thread(&Controller::process_args, this);
    parser_thread.detach();
};

