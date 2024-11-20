#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "icommand.hpp"
#include <iostream>
#include <memory>

namespace model
{

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

struct Geometry
{
public:
    Geometry(int x = 0, int y = 0, int w = 0, int h = 0) : _x(x), _y(y), _w(w), _h(h) {}
    int getX() const { return _x; }
    int getY() const { return _y; } 
    int getH() const { return _h; }
    int getW() const { return _w; } 
    void setGeometry(int x, int y, int w, int h)
    {
        _x = x;
        _y = y;
        _w = w;
        _h = h;
    }
private:
    int _x, _y, _w, _h;
};

class Item
{
public:
    using Atributes = std::unordered_map<std::string, cli::Var_SID>;

    Item(int x, int y, int w, int h, const Atributes atributes) : _geometry(x, y, w, h), _atributes(atributes) {}
    virtual ~Item() = default;
    Geometry get_geometery(){return _geometry;};
    const Atributes& get_atributes(){return _atributes;};
protected:
    inline static int id = 0;
    Geometry _geometry;
    Atributes _atributes;
};

}
#endif //  SHAPE_HPP
