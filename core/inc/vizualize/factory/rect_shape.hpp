#ifndef RECT_SHAPE_HPP
#define RECT_SHAPE_HPP

#include "ashape.hpp"
#include <memory>

namespace core
{

class RectShape : public Ashape 
{
public:
    RectShape(const model::Item& item) : Ashape(item){};
    virtual ~RectShape() = default;
    virtual void draw(std::shared_ptr<ICanvas> canvas) override;
private:
};

}
#endif // !CIRCLE_SHAPE_HPP
