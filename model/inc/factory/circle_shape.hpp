#ifndef CIRCLE_SHAPE_HPP
#define CIRCLE_SHAPE_HPP
#include "shape.hpp"
namespace model
{
class CircleShape : public IShape
{
private:
    int _radius; 
public:
    CircleShape(int x, int y, int r);
    int getRadius(){return _radius;};
};
};
#endif //  CIRCLE_SHAPE_HPP
