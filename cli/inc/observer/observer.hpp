#ifndef OBSERVER_HPP 
#define OBSERVER_HPP
#include "command.hpp"
#include <memory>

namespace cli 
{
class Observer
{
public:
    virtual void update_cli(const std::shared_ptr<Command>& cmd) = 0;
};
};
#endif //  OBSERVER_HPP!
