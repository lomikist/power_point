#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "icommand.hpp"
#include <iostream>
#include <memory>

namespace model
{
using Atributes = std::unordered_map<std::string, cli::Var_SID>;

struct RGB
{
    RGB(int r, int g, int b);
    int _r;
    int _g;
    int _b;
}; 

struct Geometry
{
public:
    Geometry(int x = 0, int y = 0, int w = 0, int h = 0); 
    int getX() const;
    int getY() const; 
    int getH() const;
    int getW() const;
    void setX(int x);
    void setY(int y); 
    void setH(int h);
    void setW(int w);
    void setGeometry(int x, int y, int w, int h);
private:
    int _x, _y, _w, _h;
};

class Item
{
public:
    Item(int x, int y, int w, int h, const Atributes& atributes);
    Geometry get_geometery() const;
    const Atributes& get_atributes() const;
    Atributes& get_atributes();
    void set_geometer(Geometry);
    void set_atributes(const Atributes& other);
    int get_id();
private:
    inline static int s_id = 0;
    Geometry _geometry;
    Atributes _atributes;
    int _id;
};

}
#endif //  SHAPE_HPP
