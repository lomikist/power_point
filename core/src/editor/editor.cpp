#include "editor.hpp"
#include "controller.hpp"
#include "iobserver.hpp"
#include <memory>

using namespace core;

void Editor::set_model(std::shared_ptr<model::Model> model)
{
    _model = model; 
};

void Editor::notifyObservers()
{
    for (auto&& observer : _observers)
    {
        observer->update();
    }
};

void Editor::addObserver(std::shared_ptr<IObserver> new_observer) 
{
    _observers.push_back(new_observer); 
} 

void Editor::process_action(std::shared_ptr<Iaction> action)
{
    _undo_stack.push(action->do_action(_model));
    while (!_rendo_stack.empty() && _rendo_stack.top()){
        _rendo_stack.pop();
    }
    notifyObservers();
}

void Editor::undo_action()
{
    if (!_undo_stack.empty())
    {
        _rendo_stack.push(_undo_stack.top()->do_action(_model));
        _undo_stack.pop();
        notifyObservers();
    }
    else 
    {
        core::Controller::instance()->get_logger()->notify_loggers("Core: no state for undo");
    }
}

void Editor::rendo_action()
{
    if (!_rendo_stack.empty())
    {
        _undo_stack.push(_rendo_stack.top()->do_action(_model));
        _rendo_stack.pop();
        notifyObservers();
    }
    else 
    {
        core::Controller::instance()->get_logger()->notify_loggers("Core: no state for rendo");
    }
}

