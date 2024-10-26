#ifndef RECT_SHAPE_HPP
#define RECT_SHAPE_HPP
#include "shape.hpp"
#include <iostream>
#include <memory>
namespace model
{
class RectShape : public AShape
{
private:
    class RectAtribute : public AShape::AAtribute
    {
    protected:
        int _width;
        int _height;
    public:
        RectAtribute(int width, int height, RGB color) : AShape::AAtribute(RectShape::id, color) , _width(width), _height(height)
        {
            RectShape::id++;
        };
    };
    RectAtribute _atributes;
public:
    RectShape(int x, int y, int width, int height, RGB color = {256, 256, 256});
    RectAtribute getAtributes();
    Geometry getGeometry();
};
};
#endif //  RECT_SHAPE_HPP
