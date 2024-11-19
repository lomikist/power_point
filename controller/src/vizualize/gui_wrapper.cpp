#include "gui_wrapper.hpp"
#include "guilogger.hpp"

using namespace core;

GuiPainterWrapper::GuiPainterWrapper(QPainter* painter) :  _device(painter)
{
};

void GuiPainterWrapper::draw_line(int x, int y, int w, int h) 
{
    _device->drawLine(x, y, w, h);
};
void GuiPainterWrapper::draw_elips(int x, int y, int w, int h)
{
    _device->drawEllipse(x, y, w, h);
};
void GuiPainterWrapper::draw_rect(int x, int y, int w, int h) 
{
    _device->drawRect(x, y, w, h);
};
void GuiPainterWrapper::draw_text(int x, int y, int w, int h, const std::string& content) 
{
    _device->drawText(x, y, QString::fromStdString(content));
};

