#ifndef OBSERVER_HPP 
#define OBSERVER_HPP

namespace core 
{
class IObserver 
{
public:
    virtual ~IObserver(){};
    virtual void update() = 0;
};
}
#endif // !OBSERVER_HPP 

