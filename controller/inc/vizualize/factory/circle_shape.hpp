#ifndef CIRCLE_SHAPE_HPP
#define CIRCLE_SHAPE_HPP

#include "ishape.hpp"
#include "item.hpp"

namespace core
{
class CircleShape : public Ishape 
{
public:
    CircleShape(std::shared_ptr<model::Item>& item) : Ishape(item){};
    virtual ~CircleShape() = default;
    virtual void draw(std::shared_ptr<ICanvas> canvas) override;
private:
};
}
#endif // !CIRCLE_SHAPE_HPP
