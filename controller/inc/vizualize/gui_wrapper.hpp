#ifndef GUI_WRAPPER_HPP
#define GUI_WRAPPER_HPP

#include "icanvas.hpp"
#include "qpainter.h"

namespace core
{
class GuiPainterWrapper : public ICanvas
{
public:
    virtual ~GuiPainterWrapper() = default;
    GuiPainterWrapper(QPainter* painter);
    virtual void draw_line(int x, int y, int w, int h) override;
    virtual void draw_elips(int x, int y, int w, int h) override;
    virtual void draw_rect(int x, int y, int w, int h) override;
    virtual void draw_text(int x, int y, int w, int h, const std::string& content) override;
private:
    QPainter* _device;
};
}
#endif // !GUI_WRAPPER_HPP
