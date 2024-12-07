#include "add_slide_action.hpp"
#include "model.hpp"
#include "remove_slide_action.hpp"

using namespace core;

AddSlideAction::AddSlideAction(model::Page slide, int index) : _current_slide(slide), _index(index)
{};

std::shared_ptr<Iaction> AddSlideAction::do_action(std::shared_ptr<model::Model> model)
{
    int slides_size;
    if (_index == -1 && !model->get_slides().empty()){
        slides_size = model->get_slides().size();
    }
    else if (_index == -1) {
        slides_size = 0;
    }
    else {
        slides_size = _index;
    }
    model->add_slide(_current_slide, slides_size);
    return std::make_shared<RemoveSlideAction>(slides_size);
}; 

