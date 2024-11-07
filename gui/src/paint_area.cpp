#include "paint_area.hpp"
#include "qimage.h"
#include "qnamespace.h"

using namespace gui;
PaintArea::PaintArea(QWidget* parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    _image = new QImage( QSize(1000, 800), QImage::Format_RGB32 );
    _image->fill(Qt::white);
    
    _painter = new QPainter(_image);
}

void PaintArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::gray);
    if (_image)
    {
        int x = (width() - _image->width()) / 2;
        int y = (height() - _image->height()) / 2;
        painter.drawImage(x, y, *_image);
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

void PaintArea::setImage(QImage* image)
{
    _image = image;
};

