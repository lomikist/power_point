#ifndef RECT_SHAPE_HPP
#define RECT_SHAPE_HPP
#include "shape.hpp"
namespace model
{
class RectShape : public Shape
{
private:
    int width, height;

public:
    RectShape(int x, int y, int width, int height)
        : Shape(x, y), width(width), height(height) {}
};
};
#endif //  RECT_SHAPE_HPP
