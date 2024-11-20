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
class Controller : public std::enable_shared_from_this<Controller> 
{
private:
    QTimer timer;
    Controller ();
public:
    ~Controller ();
    static Controller&  get_instance();
    cli::Parser&        get_parser();
private:
    std::shared_ptr<gui::GuiController> _gui_controller;
    std::shared_ptr<model::Model> _model;
    std::unique_ptr<cli::Parser> _parser;

    Editor&     _editor = Editor::get_instance();
    Vizualizer& _vizualizer = Vizualizer::get_instance();
    Logger&     _logger = Logger::get_instance();
};
};
#endif // !CONTROLLER
