#include "circle_shape.hpp"
#include "ostream_wrapper.hpp"
#include "gui_wrapper.hpp"
#include <memory>

using namespace core;

void CircleShape::draw(std::shared_ptr<ICanvas> canvas) 
{
    cli::RGB color = std::get<cli::RGB>(_item->get_atributes().at("-c"));
    QBrush brush(QColor(color._r, color._g, color._b));
 
    canvas->draw_elipse(_item->get_geometery().getX(), _item->get_geometery().getY(),
                        _item->get_geometery().getW(), _item->get_geometery().getH(),
                        color, color);

};
