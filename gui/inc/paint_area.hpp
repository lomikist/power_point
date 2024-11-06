#ifndef PAINT_AREA_HPP
#define PAINT_AREA_HPP 

#include "qimage.h"
#include "qpainter.h"
#include "qwidget.h"
#include <iostream>

namespace gui
{
class PaintArea : public QWidget
{
    Q_OBJECT
public:
    PaintArea(QWidget* parent = nullptr);
    QImage*    getImage();
    QPainter*   getPainter(); 
    void        setImage(QImage* image);
protected:
    QImage*    _image;
    QPainter*   _painter;
    void paintEvent(QPaintEvent* event) override;
};
}

#endif // !PAINT_AREA_HPP
