#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "type.hpp"

namespace model
{

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
    Item(int x, int y, int w, int h, const cli::Atributes& atributes);
    Geometry get_geometery() const;
    const cli::Atributes& get_atributes() const;
    cli::Atributes& get_atributes();
    void set_geometer(Geometry);
    void set_atributes(const cli::Atributes& other);
    int get_id();
private:
    inline static int s_id = 0;
    Geometry _geometry;
    cli::Atributes _atributes;
    int _id;
};

}
#endif //  SHAPE_HPP
