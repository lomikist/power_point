#include "circle_shape.hpp"
#include <iostream>
#include <ostream>
using namespace model;

CircleShape::CircleShape(int x, int y, int radius)
    : IShape(x, y), _radius(radius)
{
    std::cout << "shape created (implement it) circle\n";
}
