#include "rect_shape.hpp"

using namespace core;

void RectShape::draw(std::shared_ptr<ICanvas> canvas) 
{
   canvas->draw_rect(_item->get_geometery().getX(), _item->get_geometery().getY(),
                      _item->get_geometery().getW(), _item->get_geometery().getH());
};
