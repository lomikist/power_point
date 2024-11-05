#include "paint_area.hpp"

using namespace gui;
PaintArea::PaintArea(QWidget* parent, QPainter* painter) : QWidget(parent), _painter(painter)
{
    setAttribute(Qt::WA_StaticContents);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setStyleSheet("border: 2px solid black;");
}

void PaintArea::paintEvent(QPaintEvent* event)
{
    if (_painter == nullptr)
        _painter = new QPainter(this);
    QRect borderRect = rect().adjusted(1, 1, -1, -1); // Adjust to fit within widget bounds
    _painter->drawRect(borderRect);   
}

