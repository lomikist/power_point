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
    void print(std::ostream& os) override;
    CircleShape(int x, int y, int r);
};
};
#endif //  CIRCLE_SHAPE_HPP
