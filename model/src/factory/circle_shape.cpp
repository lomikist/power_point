#include "circle_shape.hpp"
#include <iostream>
#include <ostream>
using namespace model;


void CircleShape::print(std::ostream& os)
{
    os << "x - "<< _x \
       << " y - " << _y \
       << " h - " << _radius << std::endl; 
};

CircleShape::CircleShape(int x, int y, int radius)
    : IShape(x, y), _radius(radius)
{
    std::cout << "shape created (implement it) circle";
}
