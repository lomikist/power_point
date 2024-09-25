#ifndef SUBJECT_HPP 
#define SUBJECT_HPP
#include "observer.hpp"

namespace cli 
{
class Subject 
{
public:
    virtual void add_observer(std::shared_ptr<cli::Observer>) = 0;
    virtual void remove_observer(std::shared_ptr<cli::Observer>) = 0;
    virtual void notify_observers(const std::shared_ptr<Command>&) = 0;
};
};
#endif //  SUBJECT_HPP!
