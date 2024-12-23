#include "textbox_shape.hpp"
#include "ostream_wrapper.hpp"
#include "gui_wrapper.hpp"
#include <memory>
#include <string>

using namespace core;

void TextBoxShape::draw(std::shared_ptr<ICanvas> canvas) 
{
    if (_item->get_atributes().find("-content") == _item->get_atributes().end()) // it never will hapen
        throw std::runtime_error("Core: no content");

    cli::RGB color = std::get<cli::RGB>(_item->get_atributes().at("-c"));
    QBrush brush(QColor(color._r, color._g, color._b));
 
    auto content = std::get<std::string>(_item->get_atributes().at("-content")); 
    canvas->draw_text(_item->get_geometery().getX(), _item->get_geometery().getY(),
                      _item->get_geometery().getW(), _item->get_geometery().getH(), 
                      color, color, content);
}
