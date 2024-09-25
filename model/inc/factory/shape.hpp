#ifndef SHAPE_HPP
#define SHAPE_HPP
namespace model
{
class Shape {
protected:
    int x, y;  // Common position for all shapes
public:
    Shape(int x = 0, int y = 0) : x(x), y(y) {}
    virtual ~Shape() = default;
    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

};
#endif //  SHAPE_HPP
