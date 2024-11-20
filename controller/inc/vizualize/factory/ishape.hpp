#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "icanvas.hpp"
#include "item.hpp"

namespace core
{
struct Ishape 
{
    Ishape(std::shared_ptr<model::Item>& item):_item(item){};
    virtual ~Ishape() = default;
    virtual void draw(std::shared_ptr<ICanvas> canvas) = 0; 
    std::shared_ptr<model::Item> _item;
};
}

#endif // !ISHAPE_HPP
