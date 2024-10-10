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
    void print(std::ostream& os) override;
};
};
#endif //  CIRCLE_SHAPE_HPP
