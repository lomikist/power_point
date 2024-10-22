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
        _painter->drawRect(
            rect_shape->_geometry.getX(),
            rect_shape->_geometry.getY(),
            rect_shape->getWidth(),
            rect_shape->getHeight()
        );
    }

    void draw(const CirclePtr& circle_shape) override {
        _painter->drawEllipse(
            circle_shape->_geometry.getX(),
            circle_shape->_geometry.getY(),
            circle_shape->getRadius(),
            circle_shape->getRadius()
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
        _scene->addRect(
            rect_shape->_geometry.getX(),
            rect_shape->_geometry.getY(),
            rect_shape->getWidth(),
            rect_shape->getHeight()
        );
    };

    void draw(const CirclePtr& circle_shape) override {
        _scene->addEllipse(
            circle_shape->_geometry.getX(),
            circle_shape->_geometry.getY(),
            circle_shape->getRadius(),
            circle_shape->getRadius()
        );
    }
};

}
#endif// !QT_WRAPPER_HPP
