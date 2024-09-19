#ifndef CONTROLLER
#define CONTROLLER
#include "parser.hpp"
#include <memory>
namespace core
{
class Controller 
{
public:
    Controller ();
    Controller (Controller  &&) = default;
    Controller (const Controller  &) = default;
    Controller  &operator=(Controller  &&) = default;
    Controller  &operator=(const Controller  &) = default;
    ~Controller ();
    void start();
private:
    std::shared_ptr<cli::Parser> _parser; 
};
};
#endif // !CONTROLLER
