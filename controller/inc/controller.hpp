#ifndef CONTROLLER
#define CONTROLLER
#include <memory>
#include "model.hpp"
#include "observer.hpp"
#include "parser.hpp"
namespace core
{
class Controller : public cli::Observer, public std::enable_shared_from_this<Controller>
{
public:
    Controller ();
    Controller (Controller  &&) = default;
    Controller  &operator=(Controller  &&) = default;
    ~Controller ();
    void start();
    void update_cli(const std::shared_ptr<cli::Command>& cmd) override;
private:
    std::unique_ptr<cli::Parser> _parser;
    std::unique_ptr<model::Model> _model;
};
};
#endif // !CONTROLLER
