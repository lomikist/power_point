#ifndef QT_WRAPPER_HPP
#define QT_WRAPPER_HPP
#include "icanvas.hpp"
#include "qgraphicsscene.h"
#include "qpaintdevice.h"
#include "qpainter.h"
#include "rect_shape.hpp"
#include "circle_shape.hpp"
#include "slide.hpp"
#include <iostream>

namespace core 
{
class QtWrapper : public ICanvas
{
private:
    std::unique_ptr<ICanvas> _canvas_impl;
public:
    QtWrapper(QGraphicsView* view);
    QtWrapper(QPaintDevice* device, QPainter* painter);
    virtual ~QtWrapper(){};
    virtual void draw(const RectPtr& rect_shape) override; 
    virtual void draw(const CirclePtr& circle_shape) override; 
};

class PaintDeviceCanvas : public ICanvas {
private:
    QPainter* _painter;
public:
    PaintDeviceCanvas(QPainter* p) : _painter(p) {}

    void draw(const RectPtr& rect_shape) override {
        auto geometry = rect_shape->getGeometry(); 
        _painter->drawRect(
            geometry.getX(),
            geometry.getY(),
            geometry.getW(),
            geometry.getH()
        );
    }

    void draw(const CirclePtr& circle_shape) override {
        auto geometry = circle_shape->getGeometry(); 
        _painter->drawEllipse(
            geometry.getX(),
            geometry.getY(),
            geometry.getW(),
            geometry.getH()
        );
    }
};


class GraphicsSceneCanvas : public ICanvas 
{
private:
    QGraphicsScene* _scene;
public:
    GraphicsSceneCanvas(QGraphicsScene* s) : _scene(s)
    {};

    void draw(const RectPtr& rect_shape) override {
        auto geometry = rect_shape->getGeometry(); 
        _scene->addRect(
            geometry.getX(),
            geometry.getY(),
            geometry.getW(),
            geometry.getH()
        );
    };

    void draw(const CirclePtr& circle_shape) override {
        auto geometry = circle_shape->getGeometry(); 
        _scene->addEllipse(
            geometry.getX(),
            geometry.getY(),
            geometry.getW(),
            geometry.getH()
        );
    }
};

}
#endif// !QT_WRAPPER_HPP
