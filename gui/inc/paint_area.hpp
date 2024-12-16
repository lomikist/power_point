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
    QImage*     getImage();
    QPainter*   getPainter(); 
    void        setImage(QImage* image);
    void        setImageScale(int scale);
protected:
    QImage*     _image;
    QPainter*   _painter;
    double      _image_scale = 1.0;
    void wheelEvent(QWheelEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};
}

#endif // !PAINT_AREA_HPP
