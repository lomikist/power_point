#ifndef ICANVAS_HPP
#define ICANVAS_HPP

#include <string>

namespace core 
{
class ICanvas 
{
public:
    virtual ~ICanvas() = default;
    virtual void draw_line(int x, int y, int w, int h) = 0;
    virtual void draw_elips(int x, int y, int w, int h) = 0;
    virtual void draw_rect(int x, int y, int w, int h) = 0;
    virtual void draw_text(int x, int y, int w, int h, const std::string& content) = 0;
};
}
#endif // !ICANVAS_HPP
