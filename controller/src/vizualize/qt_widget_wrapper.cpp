#include "qt_widget_wrapper.hpp"

using namespace core;

PaintDeviceCanvas::PaintDeviceCanvas(QPainter* painter) : _painter(painter)
{
}

void PaintDeviceCanvas::draw(const RectPtr& rect_shape)
{
    if (_painter)
    {
        auto geometry = rect_shape->getGeometry(); 
        std::cout << "drawing a rectangle";
        _painter->drawRect(
            geometry.getX(),
            geometry.getY(),
            geometry.getW(),
            geometry.getH()
        );
    }
}

void PaintDeviceCanvas::draw(const CirclePtr& circle_shape)
{
    if (_painter)
    {
        auto geometry = circle_shape->getGeometry(); 
        std::cout << "drawing a circle ";
        _painter->drawEllipse(
            geometry.getX(),
            geometry.getY(),
            geometry.getW(),
            geometry.getH()
        );
    }
}

