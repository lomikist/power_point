#ifndef RECT_SHAPE_HPP
#define RECT_SHAPE_HPP

#include "ishape.hpp"
#include <memory>

namespace core
{

class RectShape : public Ishape 
{
public:
    RectShape(std::shared_ptr<model::Item>& item) : Ishape(item){};
    virtual ~RectShape() = default;
    virtual void draw(std::shared_ptr<ICanvas> canvas) override;
private:
};

}
#endif // !CIRCLE_SHAPE_HPP
