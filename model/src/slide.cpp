#include "slide.hpp"
#include <pstl/glue_algorithm_defs.h>
#include <vector>

using namespace model;

Slide::Slide(const std::string& title) : _title(title), _id(s_id)
{
    Slide::s_id++;
};

void Slide::add_item(Element shape) 
{
    _shapes.push_back(shape);
};

int Slide::get_id() const 
{
    return _id;
};

const Content& Slide::get_content() const
{
    return _shapes;
}; 

void Slide::set_content(const Content& shapes)
{
    _shapes = shapes;
}; 

const std::string&  Slide::get_title() const
{
    return _title;
};

void Slide::set_title(const std::string& title)
{
    _title = title;
};

void Slide::remove_item(int id)
{
    _shapes.erase(
        std::remove_if(_shapes.begin(), _shapes.end(), [id](auto&& item){
            return item->get_id() == id;
        }),
        _shapes.end()
    );
};

Element Slide::get_item(int id)
{
    auto item_it = std::find_if(_shapes.begin(), _shapes.end(), [id](auto&& item){
            return item->get_id() == id;
    });
    if (item_it == _shapes.end())
        throw std::runtime_error(std::string("Model: can't get item with id - " + std::to_string(id)));
    return *item_it;
};


