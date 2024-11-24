#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "icanvas.hpp"
#include "item.hpp"
#include <memory>

namespace core
{
struct Ishape 
{
    Ishape(const model::Item& item) : _item(std::make_shared<model::Item>(item)){};
    virtual ~Ishape(){};
    virtual void draw(std::shared_ptr<ICanvas> canvas) = 0; 
    std::shared_ptr<model::Item> _item;
};
}

#endif // !ISHAPE_HPP
