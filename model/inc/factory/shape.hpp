#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <memory>
namespace model
{

class AShape {
protected:
    struct RGB
    {
        RGB(int r, int g, int b) :
            _r(r), _g(g), _b(b){};
        RGB(const RGB& other) : _r(other._r), _g(other._g), _b(other._b)
        {};

        RGB& operator=(const RGB& other)
        {
            if (this != &other)
            {
                _r = other._r;
                _g = other._g;
                _b = other._b;
            }
            return *this;
        }
        int _r;
        int _g;
        int _b;
    }; 
    class AAtribute
    {
    public:
        RGB getColor(){return _color;};
        int getId(){return _id;}
        void setColoer(const RGB& color){ _color = color;}
        AAtribute(int id, RGB color) : _id(id), _color(color) {};
        virtual ~AAtribute(){};
    protected:
        int _id;
        RGB _color;
    }; 
    struct Geometry
    {
    public:
        Geometry(int x = 0, int y = 0, int w = 0, int h = 0) : _x(x), _y(y), _w(w), _h(h) {}
        int getX() const { return _x; }
        int getY() const { return _y; } 
        int getH() const { return _h; }
        int getW() const { return _w; } 
        void setGeometry(int x, int y, int w, int h) {
            _x = x;
            _y = y;
            _w = w;
            _h = h;
        }
    private:
        int _x, _y, _w, _h;
    };
    inline static int id = 0;
    Geometry _geometry;
public:
    AShape(int x = 0, int y = 0, int w = 0, int h = 0) : _geometry(x, y, w, h) {}
    virtual ~AShape() = default;
};
}
#endif //  SHAPE_HPP
