#include "rect_shape.hpp"
#include "shape.hpp"
#include <iostream>
using namespace model;

RectShape::RectShape(int x, int y, int width, int height, RGB color ) :
    AShape(x, y, width, height), 
    _atributes(width, height, color)
{};

RectShape::RectAtribute RectShape::getAtributes()
{
    return _atributes;
};

AShape::Geometry RectShape::getGeometry()
{
    return _geometry;
};

