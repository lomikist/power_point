#ifndef PAINT_AREA_HPP
#define PAINT_AREA_HPP 

#include "qpainter.h"
#include "qwidget.h"
#include <iostream>

namespace gui
{
class PaintArea : public QWidget {
    Q_OBJECT
public:
    PaintArea(QWidget* parent = nullptr, QPainter* painter = nullptr);
protected:
    QPainter* _painter;

    void paintEvent(QPaintEvent* event) override;
};
}

#endif // !PAINT_AREA_HPP
