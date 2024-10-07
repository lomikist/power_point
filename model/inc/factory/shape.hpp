#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <ostream>
namespace model
{
class IShape {
protected:
    int _x, _y;
public:
    IShape(int x = 0, int y = 0) : _x(x), _y(y) {}
    virtual ~IShape() = default;
    virtual void print(std::ostream& os) = 0; 
    int getX() const { return _x; }
    int getY() const { return _y; }
    void setPosition(int x, int y) {
        _x = x;
        _y = y;
    }
};

};
#endif //  SHAPE_HPP
