#include "circle_shape.hpp"
#include "shape.hpp"
#include <iostream>
#include <ostream>
using namespace model;

CircleShape::CircleShape(int x, int y, int r, RGB color ) : 
    AShape(x, y, r, r),
    _atributes(r, color)
{};

CircleShape::CircleAtribute CircleShape::getAtributes()
{
    return _atributes;
};

AShape::Geometry CircleShape::getGeometry()
{
    return _geometry;
};

