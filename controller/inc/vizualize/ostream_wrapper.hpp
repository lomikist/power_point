#ifndef OSTREAM_WRAPPER_HPP
#define OSTREAM_WRAPPER_HPP

#include "icanvas.hpp"
#include <iostream>
namespace core 
{
class OstreamWrapper : public ICanvas
{
private:
    std::ostream* _device;
public:
    ~OstreamWrapper() = default;
    OstreamWrapper(std::ostream& device);
    virtual void draw(const RectPtr& rect_shape) override; 
    virtual void draw(const CirclePtr& circle_shape) override; 
};
}


#endif// !OSTREAM_WRAPPER_HPP
