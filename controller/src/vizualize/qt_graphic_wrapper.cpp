#include "qt_graphic_wrapper.hpp"

using namespace core;

GraphicsSceneCanvas::GraphicsSceneCanvas(QGraphicsScene* s) : _scene(s)
{};

void GraphicsSceneCanvas::draw(const RectPtr& rect_shape)
{
    auto geometry = rect_shape->getGeometry(); 
    _scene->addRect(
        geometry.getX(),
        geometry.getY(),
        geometry.getW(),
        geometry.getH()
    );
};

void GraphicsSceneCanvas::draw(const CirclePtr& circle_shape)
{
    auto geometry = circle_shape->getGeometry(); 
    _scene->addEllipse(
        geometry.getX(),
        geometry.getY(),
        geometry.getW(),
        geometry.getH()
    );
}

