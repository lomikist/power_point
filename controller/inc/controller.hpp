#ifndef CONTROLLER
#define CONTROLLER
#include <memory>
#include "editor.hpp"
#include "vizualize.hpp"
#include "model.hpp"
#include "parser.hpp"
#include "icommand_visitor.hpp"
namespace core
{
class Controller : public std::enable_shared_from_this<Controller> 
{
public:
    Controller ();
    Controller (Controller  &&) = default;
    /*Controller  &operator=(Controller  &&) = default;*/
    ~Controller ();
    void start();
private:
    std::unique_ptr<cli::Parser> _parser;
    std::shared_ptr<model::Model> _model;
    Editor& _editor = Editor::get_instance();
    Vizualizer& _vizualizer = Vizualizer::get_instance();
};
};
#endif // !CONTROLLER
