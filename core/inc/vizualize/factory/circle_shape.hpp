#ifndef CIRCLE_SHAPE_HPP
#define CIRCLE_SHAPE_HPP

#include "ashape.hpp"
#include "item.hpp"

namespace core
{
class CircleShape : public Ashape 
{
public:
    CircleShape(const model::Item& item) : Ashape(item){};
    virtual ~CircleShape() = default;
    virtual void draw(std::shared_ptr<ICanvas> canvas) override;
};
}
#endif // !CIRCLE_SHAPE_HPP
