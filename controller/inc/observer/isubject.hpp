#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "iobserver.hpp"
#include <memory>
#include <vector>

namespace core 
{
class ISubject
{
public:
    virtual void notifyObservers() = 0;
    virtual void addObserver(std::shared_ptr<IObserver> observer) = 0; 
protected:
    std::vector<std::shared_ptr<IObserver>> _observers;
};
}
#endif // !SUBJECT_HPP
