#include "paint_area.hpp"
#include "gui_controller.hpp"
#include "qevent.h"
#include "qimage.h"
#include "qnamespace.h"
#include <algorithm>

using namespace gui;

PaintArea::PaintArea(QWidget* parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    _image = new QImage( QSize(PAREA_WIDTH, PAREA_HEIGHT), QImage::Format_RGB32 );
    _image->fill(Qt::white);

    _painter = new QPainter(_image);
}

void PaintArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::gray);
    if (_image)
    {
        int x = (width() - _image->width() * _image_scale) / 2;
        int y = (height() - _image->height() * _image_scale) / 2;

        QTransform transform;
        transform.translate(x, y);
        transform.scale(_image_scale, _image_scale);

        painter.setTransform(transform);
        painter.drawImage(0, 0, *_image);
    } 
}

QImage* PaintArea::getImage()
{
    return _image;
};

QPainter* PaintArea::getPainter()
{
    return _painter;
};

void PaintArea::wheelEvent(QWheelEvent* event)
{
    if (event->angleDelta().y() > 0)
    {
        _image_scale += 0.1;
    } else
    {
        _image_scale -= 0.1;
    }
    _image_scale = std::max(0.1, std::min(_image_scale, 5.0));
    update();
}

void PaintArea::setImage(QImage* image)
{
    _image = image;
};


void PaintArea::setImageScale(int scale)
{
    _image_scale = scale;
};

