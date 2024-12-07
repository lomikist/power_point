#include "add_slide_action.hpp"
#include <ostream>
#include "remove_slide_action.hpp"

using namespace core;

RemoveSlideAction::RemoveSlideAction(int index) : _current_slide_index(index)
{};

std::shared_ptr<Iaction> RemoveSlideAction::do_action(std::shared_ptr<model::Model> model)
{
    auto temp = model->get_slide(_current_slide_index); 
    model->remove_slide(_current_slide_index);

    return std::make_shared<AddSlideAction>(temp, _current_slide_index);
}; 


