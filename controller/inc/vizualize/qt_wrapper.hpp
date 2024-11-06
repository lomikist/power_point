#ifndef QT_WRAPPER_HPP
#define QT_WRAPPER_HPP
#include "icanvas.hpp"
#include "qgraphicsscene.h"
#include "qpixmap.h"
#include "view.hpp"
#include "qt_widget_wrapper.hpp"
#include "qt_graphic_wrapper.hpp"
#include <iostream>

namespace core 
{
class QtWrapper : public ICanvas
{
private:
    std::unique_ptr<ICanvas> _canvas_impl;
public:
    QtWrapper(QGraphicsView* view);
    QtWrapper(QImage* image, QPainter* painter);

    virtual ~QtWrapper(){};
    virtual void draw(const RectPtr& rect_shape) override; 
    virtual void draw(const CirclePtr& circle_shape) override; 
};
}
#endif// !QT_WRAPPER_HPP
