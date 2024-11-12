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
    public:
        CircleAtribute(int radius, RGB color) : AShape::AAtribute(AShape::id, color) , _radius(radius)
        {
            AShape::id++;
        };
        int get_radius()
        {
            return _radius;
        }
    };
    CircleAtribute _atributes;
public:
    CircleShape(int x, int y, int r, RGB color = {256, 256, 256}); 
    CircleAtribute getAtributes();
    Geometry getGeometry();
};
};
#endif //  CIRCLE_SHAPE_HPP
