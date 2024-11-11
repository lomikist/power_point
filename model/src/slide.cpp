#include "slide.hpp"

namespace model
{
Slide::Slide(const std::string& title) : _title(title), _id(s_id)
{
    Slide::s_id++;
};

void Slide::add_shape(std::shared_ptr<AShape> shape)
{
    _shapes.push_back(shape);
};

int Slide::get_id()
{
    return _id;
};

const Content& Slide::get_content() const
{
    return _shapes;
}; 

Content& Slide::get_content()
{
    return _shapes;
}; 

const std::string&  Slide::get_title() const
{
    return _title;
};

std::string&  Slide::get_title()
{
    return _title;
};


void Slide::remove_shape(int index)
{
    if (index > _shapes.size() || index < 0)
        _shapes.erase(_shapes.begin() + index);
};
}
