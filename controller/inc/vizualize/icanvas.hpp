#ifndef ICANVAS_HPP
#define ICANVAS_HPP

#include "slide.hpp"

namespace core 
{
class ICanvas 
{
public:
    using SlidePtr = std::shared_ptr<model::Slide>;
    using RectPtr = std::shared_ptr<model::Item>;
    virtual ~ICanvas() = default;
    /*virtual void draw(const SlidePtr& slide) = 0; */
    virtual void draw(const RectPtr& slide) = 0; 
    /*virtual void draw(const CirclePtr& slide) = 0; */
};
}
#endif // !ICANVAS_HPP
