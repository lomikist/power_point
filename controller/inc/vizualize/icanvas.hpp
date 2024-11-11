#ifndef ICANVAS_HPP
#define ICANVAS_HPP

#include "rect_shape.hpp"
#include "circle_shape.hpp"
#include "slide.hpp"

namespace core 
{
class ICanvas 
{
public:
    using SlidePtr = std::shared_ptr<model::Slide>;
    using RectPtr = std::shared_ptr<model::RectShape>;
    using CirclePtr = std::shared_ptr<model::CircleShape>;
    virtual ~ICanvas() = default;
    /*virtual void draw(const SlidePtr& slide) = 0; */
    virtual void draw(const RectPtr& slide) = 0; 
    virtual void draw(const CirclePtr& slide) = 0; 
};
}
#endif // !ICANVAS_HPP
