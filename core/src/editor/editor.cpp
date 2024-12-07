#include "editor.hpp"
#include "icommand.hpp"
#include "iobserver.hpp"
#include "item.hpp"
#include <memory>

using namespace core;

Editor& Editor::get_instance()
{
    static Editor _instance;
    return _instance;
};

void Editor::set_model(std::shared_ptr<model::Model> model)
{
    _model = std::move(model); 
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
    _rendo_stack.push(_undo_stack.top()->do_action(_model));
    _undo_stack.pop();
    notifyObservers();
}

void Editor::rendo_action()
{
    _undo_stack.push(_rendo_stack.top()->do_action(_model));
    _rendo_stack.pop();
    notifyObservers();
}

