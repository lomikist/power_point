#include "add_item_action.hpp"
#include "remove_item_action.hpp"

using namespace core;

std::shared_ptr<Iaction> AddItemAction::do_action(std::shared_ptr<model::Model> model)
{
    model->get_slide(_slide_index)->add_item(_current_item);
    return std::make_shared<RemoveItemAction>(_slide_index, _current_item->get_id());  
};

AddItemAction::AddItemAction(model::Element item, int slide_index)
                        : _current_item(item)
                        , _slide_index(slide_index){};

