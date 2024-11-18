#include "ostream_wrapper.hpp"
#include <strstream>

using namespace core;

void OstreamWrapper::draw(const RectPtr& rect_shape)
{
    auto geometry = rect_shape->get_geometery();
    *_device << "x - " << geometry.getX() << 
              " y - " << geometry.getY() <<
              " width - " << geometry.getW() <<
              " height - " << geometry.getH() << std::endl;     
}

/*void OstreamWrapper::draw(const CirclePtr& circle_shape)*/
/*{*/
/*    auto geometry = circle_shape->getGeometry();*/
/*    auto atribute = circle_shape->getAtributes();*/
/*    *_device << "x - " << geometry.getX() <<*/
/*              " y - " << geometry.getY() <<*/
/*              " r - " << atribute.get_radius() << std::endl;     */
/*}*/

OstreamWrapper::OstreamWrapper(std::ostream& device)
{
    _device = &device;
}

