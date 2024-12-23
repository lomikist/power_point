#include "gui_wrapper.hpp"
#include "guilogger.hpp"
#include "qbrush.h"

using namespace core;

GuiPainterWrapper::GuiPainterWrapper(QPainter* painter) :  _device(painter)
{};

void GuiPainterWrapper::draw_line(int x, int y, int w, int h,
                                  cli::RGB brush_color, cli::RGB pen_color) 
{
    QBrush  brush = QColor(brush_color._r, brush_color._g, brush_color._b);
    QPen    pen =  QColor(pen_color._r, pen_color._g, pen_color._b);
    _device->setPen(pen);
    _device->setBrush(brush);
    _device->drawLine(x, y, w, h);
};
void GuiPainterWrapper::draw_elipse(int x, int y, int w, int h,
                                    cli::RGB brush_color, cli::RGB pen_color)
{
    QBrush  brush = QColor(brush_color._r, brush_color._g, brush_color._b);
    QPen    pen =  QColor(pen_color._r, pen_color._g, pen_color._b);
    _device->setPen(pen);
    _device->setBrush(brush);
    _device->drawEllipse(x, y, w, h);
};
void GuiPainterWrapper::draw_rect(int x, int y, int w, int h,
                                  cli::RGB brush_color, cli::RGB pen_color) 
{
    QBrush brush = QColor(brush_color._r, brush_color._g, brush_color._b);
    QPen    pen =  QColor(pen_color._r, pen_color._g, pen_color._b);
    _device->setPen(pen);
    _device->setBrush(brush);
    _device->drawRect(x, y, w, h);
};
void GuiPainterWrapper::draw_text(int x, int y, int w, int h,
                                  cli::RGB brush_color, cli::RGB pen_color, const std::string& content) 
{
    QBrush brush = QColor(brush_color._r, brush_color._g, brush_color._b);
    QPen    pen =  QColor(pen_color._r, pen_color._g, pen_color._b);
    _device->setPen(pen);
    _device->setBrush(brush);
    _device->drawText(x, y, QString::fromStdString(content));
};

