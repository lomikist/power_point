#include "item.hpp"

using namespace model;

Geometry::Geometry(int x, int y, int w, int h) : _x(x), _y(y), _w(w), _h(h)
{}
int Geometry::getX() const { return _x; }

int Geometry::getY() const { return _y; } 

int Geometry::getH() const { return _h; }

int Geometry::getW() const { return _w; } 

void Geometry::setX(int x)
{ _x = x; };  

void Geometry::setY(int y)
{ _y = y; };  

void Geometry::setH(int h)
{ _h = h; };  

void Geometry::setW(int w)
{ _w = w; };  
 
void Geometry::setGeometry(int x, int y, int w, int h)
{
    _x = x;
    _y = y;
    _w = w;
    _h = h;
}

RGB::RGB(int r, int g, int b) : _r(r), _g(g), _b(b)
{};
 
Item::Item(int x, int y, int w, int h, const Atributes& atributes) : _geometry(x, y, w, h), _atributes(atributes), _id(s_id)
{
    s_id++;
};

Geometry Item::get_geometery() const { return _geometry;};

const Atributes& Item::get_atributes() const { return _atributes;};

Atributes& Item::get_atributes() { return _atributes;};

void Item::set_geometer(Geometry other)
{
    _geometry = other;
};
void Item::set_atributes(const Atributes& other)
{
    _atributes = other;
};

int Item::get_id()
{
    return _id;
}

