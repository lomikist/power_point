#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <ostream>
namespace model
{
class IShape {
protected:
    struct Geometry
    {
        Geometry(int x = 0, int y = 0) : _x(x), _y(y) {}
        int getX() const { return _x; }
        int getY() const { return _y; } 
        void setPosition(int x, int y) {
            _x = x;
            _y = y;
        }
    private:
        int _x, _y;
    };
public:
    IShape(int x = 0, int y = 0) : _geometry(x, y) {}
    virtual ~IShape() = default;
    Geometry _geometry;
};
}
#endif //  SHAPE_HPP
