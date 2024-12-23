#ifndef CONTROLLER
#define CONTROLLER
#include <memory>
#include "editor.hpp"
#include "gui_controller.hpp"
#include "qapplication.h"
#include "vizualize.hpp"
#include "logger.hpp"
#include "model.hpp"
#include "parser.hpp"

namespace core
{
class Controller : public QApplication
{
public:
    static Controller* instance(); 

    Controller(int &argc, char *argv[]);
    ~Controller ();

    Controller(const Controller&) = delete;
    Controller(Controller&&) = delete;
    Controller& operator=(const Controller&) = delete;
    Controller& operator=(Controller&&) = delete;

    cli::Parser&                        get_parser();
    std::shared_ptr<gui::GuiController> get_guicontroller();
    std::shared_ptr<model::Model>       get_model();
    std::shared_ptr<core::Editor>       get_editor();
    std::shared_ptr<core::Vizualizer>   get_vizualizer();
    std::shared_ptr<core::Logger>       get_logger();
private:
    std::shared_ptr<gui::GuiController> _gui_controller;
    std::shared_ptr<model::Model>       _model;
    std::unique_ptr<cli::Parser>        _parser;

    std::shared_ptr<Editor>     _editor;
    std::shared_ptr<Vizualizer> _vizualizer;
    std::shared_ptr<Logger>     _logger;
};
};
#endif // !CONTROLLER
