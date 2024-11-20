#ifndef TEXTBOX_SHAPE_HPP
#define TEXTBOX_SHAPE_HPP

#include "ishape.hpp"
#include <memory>

namespace core
{

class TextBoxShape : public Ishape 
{
public:
    TextBoxShape(std::shared_ptr<model::Item>& item) : Ishape(item){};
    virtual ~TextBoxShape() = default;
    virtual void draw(std::shared_ptr<ICanvas> canvas) override;
private:
};

}
#endif // !TEXTBOX_SHAPE_HPP
