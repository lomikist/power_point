#include "add_item_action.hpp"
#include "remove_item_action.hpp"

using namespace core;

std::shared_ptr<Iaction> RemoveItemAction::do_action(std::shared_ptr<model::Model> model)
{
    auto temp_item = model->get_slide(_current_slide_index)->get_item(_current_item_id);
    model->get_slide(_current_slide_index)->remove_item(_current_item_id);
    return std::make_shared<AddItemAction>(temp_item, _current_slide_index);
};

RemoveItemAction::RemoveItemAction(int slide_index, int id)
                        : _current_slide_index(slide_index)
                        , _current_item_id(id){};

