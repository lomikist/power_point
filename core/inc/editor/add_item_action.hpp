#ifndef ADDITEM_ACTION_HPP
#define ADDITEM_ACTION_HPP

#include "iaction.hpp"
#include "model.hpp"
#include "slide.hpp"
#include <memory>
namespace core 
{
class AddItemAction : public Iaction
{
public:
    AddItemAction(model::Element item, int slide_index);
    std::shared_ptr<Iaction> do_action(std::shared_ptr<model::Model> model) override; 
private:
    model::Element _current_item; 
    int         _slide_index;
};
}
#endif // !ADDITEM_ACTION_HPP

