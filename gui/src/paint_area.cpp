#include "paint_area.hpp"
#include "add_item_action.hpp"
#include "controller.hpp"
#include "editor.hpp"
#include "gui_controller.hpp"
#include "gui_wrapper.hpp"
#include "item.hpp"
#include "qevent.h"
#include "qimage.h"
#include "qnamespace.h"
#include "shape_factory.hpp"
#include <memory>

using namespace gui;

PaintArea::PaintArea(QVector<QPushButton*>& tools, QWidget* parent) :
                    QWidget(parent) ,
                    _tools_vector(tools)
{
    setAttribute(Qt::WA_StaticContents);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    _image = new QImage( QSize(PAREA_WIDTH, PAREA_HEIGHT), QImage::Format_RGB32 );
    _image->fill(Qt::white);

    _painter = new QPainter(_image);
}

void PaintArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::lightGray);
    if (_image)
    {
        _image_position.setX((width() - _image->width() * _image_scale) / 2);
        _image_position.setY((height() - _image->height() * _image_scale) / 2);

        QTransform transform;
        transform.translate(_image_position.x(), _image_position.y());
        painter.setTransform(transform);

        painter.drawImage(0, 0, *_image);
    } 
}

void PaintArea::mousePressEvent(QMouseEvent* event)
{
    if (_is_item_selecte)
    {
        QPoint relateive_pos = event->pos() - _image_position;  
        if (event->button() == Qt::LeftButton && _image->rect().contains(relateive_pos)) 
        {
            _press_pos = relateive_pos;
            for (auto&& item : _tools_vector)
            {
                if (item->isChecked() == true)
                {
                    model::Atributes atributes;
                    model::RGB color(12, 123,12);

                    atributes["-t"] = item->property("item_type").toString().toStdString();
                    atributes["-c"] = color;
                    atributes["-content"] = "hello darkness";
                    atributes["-i"] = 0; // change to current slide 

                    _new_item = std::make_shared<model::Item>(_press_pos.x(), _press_pos.y(),
                                                              0, 0, atributes); 
                }
            }
        }
        update();
    }
}

void PaintArea::mouseReleaseEvent(QMouseEvent* event)
{
    if (_is_item_selecte)
    {
        QPoint relateive_pos = event->pos() - _image_position;  
        if (event->button() == Qt::LeftButton && _image->rect().contains(relateive_pos)) 
        {
            _release_pos = relateive_pos;
            model::Geometry geometry(_press_pos.x(), _press_pos.y(),
                                     _release_pos.x() - _press_pos.x(),
                                     _release_pos.y() - _press_pos.y());

            _new_item->set_geometer(geometry);
            auto action  = std::make_shared<core::AddItemAction>(_new_item, 0);
            core::Controller::get_instance().get_editor()->process_action(action);
        }
        update();
    }
}

void PaintArea::mouseMoveEvent(QMouseEvent *event) 
{
    if (_is_item_selecte)
    {
        core::ShapeFactory createor; 
        auto canvas = std::make_shared<core::GuiPainterWrapper>(this->_painter);
        QPoint relateive_pos = event->pos() - _image_position;  
        if (_image->rect().contains(relateive_pos)) 
        {
            model::Geometry geometry(_press_pos.x(), _press_pos.y(),
                                     relateive_pos.x() - _press_pos.x(),
                                     relateive_pos.y() - _press_pos.y());
            _new_item->set_geometer(geometry);
            auto shape = createor.create_shape(std::get<std::string>(_new_item->get_atributes().at("-t")), *_new_item);
            shape->draw(canvas);
        }
        update();
    }
}

void PaintArea::set_image(QImage* image)
{
    _image = image;
}

void PaintArea::item_selected(bool flag)
{
    _is_item_selecte = flag;
}

void PaintArea::set_imageScale(int scale)
{
    _image_scale = scale;
}

QImage* PaintArea::get_image()
{
    return _image;
}

QPainter* PaintArea::get_painter()
{
    return _painter;
}

