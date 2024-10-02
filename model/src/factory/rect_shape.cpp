#include "rect_shape.hpp"
#include <iostream>
using namespace model;

void RectShape::print()
{
    std::cout << "x - "<< this->x \
              << " y - " << this->y \
              << " w - " << this->width \
              << " h - " << this->height << std::endl; 
};

