#ifndef RECT_SHAPE_HPP
#define RECT_SHAPE_HPP
#include "shape.hpp"
#include <iostream>
namespace model
{
class RectShape : public AShape
{
private:
    class RectAtribute : public AShape::AAtribute
    {
    protected:
        int _width, _height;

    };
public:
    RectShape(int x, int y, int width, int height);
};
};
#endif //  RECT_SHAPE_HPP
