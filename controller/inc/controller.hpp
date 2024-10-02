#ifndef CONTROLLER
#define CONTROLLER
#include <memory>
#include "model.hpp"
#include "parser.hpp"
#include "icommand_visitor.hpp"
namespace core
{
class Controller : public std::enable_shared_from_this<Controller>, public ICommandVisitor 
{
public:
    Controller ();
    Controller (Controller  &&) = default;
    Controller  &operator=(Controller  &&) = default;
    ~Controller ();

    void start();
    void visit_cmd(const std::shared_ptr<cli::AddSlideCom>& cmd) override;
    void visit_cmd(const std::shared_ptr<cli::ShowSlideCom>& cmd) override;
    void visit_cmd(const std::shared_ptr<cli::AddShapeCom>& cmd) override;
private:
    std::unique_ptr<cli::Parser> _parser;
    std::unique_ptr<model::Model> _model;
};
};
#endif // !CONTROLLER
