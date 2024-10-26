#include "ostream_wrapper.hpp"
#include <strstream>

using namespace core;

void OstreamWrapper::draw(const RectPtr& rect_shape)
{
    auto geometry = rect_shape->getGeometry();
   *_device << "x - " << geometry.getX() << 
              " y - " << geometry.getY() <<
              " width - " << geometry.getW() <<
              " height - " << geometry.getH() << std::endl;     
}

void OstreamWrapper::draw(const CirclePtr& circle_shape)
{
    auto geometry = circle_shape->getGeometry();
   *_device << "x - " << geometry.getX() <<
              " y - " << geometry.getY() <<
              " r - " << geometry.getH() << std::endl;     
}

OstreamWrapper::OstreamWrapper(std::ostream& device)
{
    _device = &device;
}


