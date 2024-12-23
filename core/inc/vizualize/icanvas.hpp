#ifndef ICANVAS_HPP
#define ICANVAS_HPP

#include "type.hpp"
#include <string>

namespace core 
{
class ICanvas 
{
public:
    virtual ~ICanvas() = default;
    virtual void draw_line(int x, int y, int w, int h ,
                           cli::RGB brush_color, cli::RGB line_color) = 0;
    virtual void draw_elipse(int x, int y, int w, int h , 
                           cli::RGB brush_color, cli::RGB line_color) = 0;
    virtual void draw_rect(int x, int y, int w, int h ,
                           cli::RGB brush_color, cli::RGB line_color) = 0;
    virtual void draw_text(int x, int y, int w, int h , 
                           cli::RGB brush_color, cli::RGB line_color,
                           const std::string& content) = 0;
};
}
#endif // !ICANVAS_HPP
