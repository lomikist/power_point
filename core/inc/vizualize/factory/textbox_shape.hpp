#ifndef TEXTBOX_SHAPE_HPP
#define TEXTBOX_SHAPE_HPP

#include "ashape.hpp"
#include <memory>

namespace core
{

class TextBoxShape : public Ashape 
{
public:
    TextBoxShape(const model::Item& item) : Ashape(item){};
    virtual ~TextBoxShape() = default;
    virtual void draw(std::shared_ptr<ICanvas> canvas) override;
private:
};

}
#endif // !TEXTBOX_SHAPE_HPP
