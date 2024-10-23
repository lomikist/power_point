#include "rect_shape.hpp"
#include <iostream>
using namespace model;

RectShape::RectShape(int x, int y, int width, int height)
    : IShape(x, y), _width(width), _height(height) {
    std::cout << "shape created (implement it)\n";
}
