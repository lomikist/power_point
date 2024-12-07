#ifndef REMOVEITEM_ACTION_HPP
#define REMOVEITEM_ACTION_HPP

#include "iaction.hpp"
#include "slide.hpp"
#include <memory>
namespace core 
{
class RemoveItemAction : public Iaction
{
public:
    RemoveItemAction(int slide_index, int id);
    std::shared_ptr<Iaction> do_action(std::shared_ptr<model::Model> model) override; 
private:
    int _current_slide_index; 
    int _current_item_id;
};
}
#endif // !REMOVEITEM_ACTION_HPP
