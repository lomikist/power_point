#include "controller.hpp"
#include "editor.hpp"
#include "guilogger.hpp"
#include "oslogger.hpp"
#include "vizualize.hpp"
#include <ctime>
#include <iostream>
#include <memory>
#include <QTimer>

using namespace core;

cli::Parser& Controller::get_parser()
{
    return *_parser;
};

std::shared_ptr<gui::GuiController> Controller::get_guicontroller(){
    return _gui_controller;
};

std::shared_ptr<model::Model> Controller::get_model()
{
    return _model;
};

Controller::Controller(int &argc, char *argv[]) :
            QApplication(argc, argv)
{

    _parser         = std::make_unique<cli::Parser>();
    _model          = std::make_shared<model::Model>();
    _gui_controller = std::make_shared<gui::GuiController>();
    _editor         = std::make_shared<core::Editor>();
    _logger         = std::make_shared<core::Logger>();
    _vizualizer     = std::make_shared<core::Vizualizer>();

    _editor->set_model(_model);
    _vizualizer->set_model(_model);

    _editor->addObserver(_gui_controller);

    _logger->add_logger(std::make_shared<OsLogger>(&std::cout));
    _logger->add_logger(std::make_shared<GuiLogger>(_gui_controller->get_screen()->get_text_browser()));
};

std::shared_ptr<core::Editor>   Controller::get_editor()
{
    return _editor;
};
std::shared_ptr<core::Vizualizer>   Controller::get_vizualizer()
{
    return _vizualizer;
};
std::shared_ptr<core::Logger>   Controller::get_logger()
{  
    return _logger;
};

Controller *Controller::instance(){
    return static_cast<Controller*>(QApplication::instance());
}

Controller::~Controller()
{};

