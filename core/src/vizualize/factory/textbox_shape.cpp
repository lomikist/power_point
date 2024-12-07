#include "textbox_shape.hpp"
#include "ostream_wrapper.hpp"
#include "gui_wrapper.hpp"
#include <memory>
#include <string>

using namespace core;

void TextBoxShape::draw(std::shared_ptr<ICanvas> canvas) 
{
    auto content = std::get<std::string>(_item->get_atributes().at("-content")); 
    canvas->draw_text(_item->get_geometery().getX(), _item->get_geometery().getY(),
                       _item->get_geometery().getW(), _item->get_geometery().getH(), content);
}
