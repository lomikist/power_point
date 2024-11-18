#include "qt_widget_wrapper.hpp"
#include "qpixmap.h"
#include <complex>

using namespace core;

PaintDeviceCanvas::PaintDeviceCanvas(QPainter* painter) :  _painter(painter)
{
};

void PaintDeviceCanvas::draw(const RectPtr& rect_shape)
{
    _painter->setPen(Qt::blue);
    _painter->setBrush(Qt::red);
    auto geometry = rect_shape->get_geometery(); 

    _painter->drawRect(
        geometry.getX(),
        geometry.getY(),
        geometry.getW(),
        geometry.getH()
    );
}

