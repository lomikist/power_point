#ifndef GUI_WRAPPER_HPP
#define GUI_WRAPPER_HPP

#include "icanvas.hpp"
#include "qpainter.h"
#include "qpen.h"

namespace core
{
class GuiPainterWrapper : public ICanvas
{
public:
    virtual ~GuiPainterWrapper() = default;
    GuiPainterWrapper(QPainter* painter);
    virtual void draw_line(int x, int y, int w, int h,
                           model::RGB brush_color, model::RGB line_color) override;
    virtual void draw_elipse(int x, int y, int w, int h,
                           model::RGB brush_color, model::RGB line_color) override;
    virtual void draw_rect(int x, int y, int w, int h, 
                           model::RGB brush_color, model::RGB line_color) override;
    virtual void draw_text(int x, int y, int w, int h,
                           model::RGB brush_color, model::RGB line_color,
                           const std::string& content) override;
private:
    QPainter*   _device;
    QPen        _current_pen;
    QBrush      _current_brush;

};
}
#endif // !GUI_WRAPPER_HPP
