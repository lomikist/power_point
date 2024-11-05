#include "qt_wrapper.hpp"
#include "qgraphicsview.h"
#include "qpainter.h"
#include "view.hpp"
#include <memory>

using namespace core;

QtWrapper::QtWrapper(QGraphicsView* view)
{
    if (view && view->scene()) {
        _canvas_impl = std::make_unique<GraphicsSceneCanvas>(view->scene());
    }
}

QtWrapper::QtWrapper(QPainter* painter)
{
    _canvas_impl = std::make_unique<PaintDeviceCanvas>(painter);
}

void QtWrapper::draw(const RectPtr& rect_shape)
{
    _canvas_impl->draw(rect_shape); 
}

void QtWrapper::draw(const CirclePtr& circle_shape)
{
    _canvas_impl->draw(circle_shape);
}

