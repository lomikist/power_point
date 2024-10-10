#include "rect_shape.hpp"
#include <iostream>
using namespace model;

void RectShape::print(std::ostream& os)
{
    os << "x - "<< _x \
       << " y - " << _y \
       << " w - " << _width \
       << " h - " << _height << std::endl; 
};

RectShape::RectShape(int x, int y, int width, int height)
    : IShape(x, y), _width(width), _height(height) {
    std::cout << "shape created (implement it)\n";
}
