#include "slide.hpp"


namespace model
{
Slide::Slide(const std::string& title, int index)
{
    std::cout << "slide ctor";
    _title = title;
    _index = index;
};

void Slide::add_shape(std::shared_ptr<IShape> shape)
{
    _shapes.push_back(shape);
};

void Slide::set_index(int index)
{
    _index = index;
}
}
