#ifndef CONTROLLER
#define CONTROLLER
#include <memory>
#include "editor.hpp"
#include "gui_controller.hpp"
#include "qtimer.h"
#include "vizualize.hpp"
#include "logger.hpp"
#include "model.hpp"
#include "parser.hpp"
#include "view.hpp"

namespace core
{
class Controller 
{
public:
    ~Controller ();
    static Controller&                  get_instance();
    cli::Parser&                        get_parser();
    std::shared_ptr<gui::GuiController> get_guicontroller();
    std::shared_ptr<model::Model>       get_model();
    std::shared_ptr<core::Editor>       get_editor();
    std::shared_ptr<core::Vizualizer>   get_vizualizer();
    std::shared_ptr<core::Logger>       get_logger();
    
private:
    Controller();

    std::shared_ptr<gui::GuiController> _gui_controller;
    std::shared_ptr<model::Model>       _model;
    std::unique_ptr<cli::Parser>        _parser;

    std::shared_ptr<Editor>     _editor;
    std::shared_ptr<Vizualizer> _vizualizer;
    std::shared_ptr<Logger>     _logger;
};
};
#endif // !CONTROLLER
