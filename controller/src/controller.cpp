#include "controller.hpp"
#include "editor.hpp"
#include "gui_controller.hpp"
#include "guilogger.hpp"
#include "icanvas.hpp"
#include "ilogger.hpp"
#include "oslogger.hpp"
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
    _vizualizer.set_model(_model);
    _editor.addObserver(_gui_controller);
    _logger.add_logger(std::make_shared<OsLogger>(&std::cout));
    _logger.add_logger(std::make_shared<GuiLogger>(_gui_controller->get_screen()->get_text_browser()));
}

Controller::~Controller()
{
};

