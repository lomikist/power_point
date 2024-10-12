#include "slide.hpp"


namespace model
{
Slide::Slide(const std::string& title, int index)
{
    std::cout << "slide cretaed\n";
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

void Slide::remove_shape(int index)
{
    if (index > _shapes.size() || index < 0)
        _shapes.erase(_shapes.begin() + index);
};
}
