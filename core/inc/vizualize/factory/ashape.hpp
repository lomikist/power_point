#ifndef ASHAPE_HPP
#define ASHAPE_HPP

#include "ishape.hpp"
#include "item.hpp"
#include <memory>

namespace core
{
struct Ashape : public Ishape 
{
    Ashape(const model::Item& item) : 
        _item(std::make_shared<model::Item>(item)),
        _brush_color(1,1,1), 
        _line_color(1,1,1) 
    {
        _brush_color = std::get<model::RGB>(item.get_atributes().at("-c"));
        _line_color = std::get<model::RGB>(item.get_atributes().at("-c"));
    };
    virtual ~Ashape() = default;
    std::shared_ptr<model::Item> _item;
    model::RGB _brush_color;
    model::RGB _line_color;
};
}

#endif // !ASHAPE_HPP
