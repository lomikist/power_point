#include "slide.hpp"

using namespace model;

Slide::Slide(const std::string& title) : _title(title), _id(s_id)
{
    Slide::s_id++;
};

void Slide::add_item(const Item& shape) 
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

void Slide::remove_item(size_t index)
{
    if (index < _shapes.size())
        _shapes.erase(_shapes.begin() + index);
};

