#ifndef CIRCLE_SHAPE_HPP
#define CIRCLE_SHAPE_HPP
#include "shape.hpp"
namespace model
{
class CircleShape : public AShape
{
private:
    class CircleAtribute : public AShape::AAtribute
    {
    protected:
        int _radius;
    };
public:
    CircleShape(int x, int y, int r);
};
};
#endif //  CIRCLE_SHAPE_HPP
