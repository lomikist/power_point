#ifndef QT_WIDGET_WRAPPER_HPP
#define QT_WIDGET_WRAPPER_HPP

#include "icanvas.hpp"
#include "qimage.h"
#include "qpainter.h"
#include "view.hpp"

namespace core
{
class PaintDeviceCanvas : public ICanvas
{
private:
    /*QImage* _image;*/
    /*QPixmap* _pix_image;*/
    QPainter* _painter;

public:
    /*PaintDeviceCanvas(QImage* image, QPainter* painter);*/
    PaintDeviceCanvas(QPainter* painter);
    void draw(const RectPtr& rect_shape) override;
    void draw(const CirclePtr& circle_shape) override;
};

}
#endif // !QT_WIDGET_WRAPPER_HPP