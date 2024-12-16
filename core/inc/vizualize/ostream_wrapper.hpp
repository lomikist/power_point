#ifndef OSTREAM_WRAPPER_HPP
#define OSTREAM_WRAPPER_HPP

#include "icanvas.hpp"
#include <iostream>
namespace core 
{
class OstreamWrapper : public ICanvas
{
public:
    OstreamWrapper(std::ostream& device);
    virtual ~OstreamWrapper() = default;
    virtual void draw_line(int x, int y, int w, int h,
                           model::RGB brush_color, model::RGB line_color) override;
    virtual void draw_elipse(int x, int y, int w, int h,
                           model::RGB brush_color, model::RGB line_color) override;
    virtual void draw_rect(int x, int y, int w, int h, 
                           model::RGB brush_color, model::RGB line_color) override;
    virtual void draw_text(int x, int y, int w, int h,
                           model::RGB brush_color, model::RGB line_color,
                           const std::string& content) override;private:
    std::ostream* _device;
};
}


#endif// !OSTREAM_WRAPPER_HPP
