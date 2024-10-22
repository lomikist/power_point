#include "ostream_wrapper.hpp"
#include <strstream>

using namespace core;

void OstreamWrapper::draw(const RectPtr& rect_shape)
{
   *_device << "x - " << rect_shape->_geometry.getX() << 
              " y - " << rect_shape->_geometry.getY() <<
              " width - " << rect_shape->getWidth()   <<
              " height - " << rect_shape->getHeight() << std::endl;     
}

void OstreamWrapper::draw(const CirclePtr& circle_shape)
{
   *_device << "x - " << circle_shape->_geometry.getX() <<
              " y - " << circle_shape->_geometry.getY() <<
              " r - " << circle_shape->getRadius() << std::endl;     
}

OstreamWrapper::OstreamWrapper(std::ostream& device)
{
    _device = &device;
}


