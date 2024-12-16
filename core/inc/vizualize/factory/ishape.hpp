#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "icanvas.hpp"
#include "item.hpp"
#include <memory>

namespace core
{
struct Ishape 
{
    virtual ~Ishape(){};
    virtual void draw(std::shared_ptr<ICanvas> canvas) = 0; 
};
}

#endif // !ISHAPE_HPP
