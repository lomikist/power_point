#ifndef RECT_SHAPE_HPP
#define RECT_SHAPE_HPP
#include "shape.hpp"
#include <iostream>
namespace model
{
class RectShape : public IShape
{
private:
    int _width, _height;

public:
    RectShape(int x, int y, int width, int height);
    void print(std::ostream& os) override;
};
};
#endif //  RECT_SHAPE_HPP
