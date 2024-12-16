#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <memory>
#include <unordered_map>
#include <variant>

namespace model
{

struct RGB
{
    RGB(int r, int g, int b);
    int _r;
    int _g;
    int _b;
}; 

using Var_SID = std::variant<std::string, int, double, RGB>;
using Atributes = std::unordered_map<std::string, Var_SID>;

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
