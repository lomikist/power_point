#ifndef PAINT_AREA_HPP
#define PAINT_AREA_HPP 

#include "item.hpp"
#include "qimage.h"
#include "qpainter.h"
#include "qpoint.h"
#include "qpushbutton.h"
#include "qwidget.h"
#include <memory>

namespace gui
{
class PaintArea : public QWidget
{
    Q_OBJECT
public:
    PaintArea(QVector<QPushButton*>& tools, QWidget* parent = nullptr);
    QImage*     get_image();
    QPainter*   get_painter(); 
    void        set_image(QImage* image);
    void        set_imageScale(int scale);
    void        item_selected(bool flag); 
protected:
    QImage*     _image;
    QPainter*   _painter;
    QPoint      _image_position;
    double      _image_scale = 1.0;
    bool        _is_item_selecte = false;

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override; 
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    QVector<QPushButton*>& _tools_vector;
    std::shared_ptr<model::Item> _new_item;
    QPoint _press_pos;
    QPoint _release_pos;
};
}

#endif // !PAINT_AREA_HPP
