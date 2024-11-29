#include "editor.hpp"
#include "icommand.hpp"
#include "iobserver.hpp"
#include "item.hpp"
#include <memory>
#include <string>
#include <unordered_map>

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

void Editor::add_item(const model::Atributes& geometery,
                      const model::Atributes& atributes)
{
    int index = std::get<int>(atributes.at("-i"));
    int x = std::get<int>(geometery.at("-x"));
    int y = std::get<int>(geometery.at("-y"));
    int w = std::get<int>(geometery.at("-w"));
    int h = std::get<int>(geometery.at("-h"));

    _model->get_slide(index).add_item(model::Item(x, y, w, h, atributes));
    save_state();
    notifyObservers();
};

void Editor::remove_item(int slide_index, int shape_index)
{
    _model->get_slide(slide_index).remove_item(shape_index);
    save_state();
    notifyObservers();
};

void Editor::add_slide(int index, const std::string& name)
{
    _model->add_slide(model::Slide(name), index);
    save_state();
    notifyObservers();
};

void Editor::remove_slide(int slide_index)
{
    _model->remove_slide(slide_index);
    save_state();
    notifyObservers();
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

void Editor::save_state()
{
    if (_model)
    {
        _undo_stack.push(model::ModelMemento(_model->get_slides()));
        while (!_rendo_stack.empty()) {
            _rendo_stack.pop();
        }
    }
}

void Editor::undo_state()
{
    if (_model && !_undo_stack.empty())
    {
        _rendo_stack.push(_undo_stack.top().get_state());
        _undo_stack.pop();
        _model->set_slides(_undo_stack.top().get_state());
    }
    notifyObservers();
}

void Editor::rendo_state()
{
    if (_model && !_rendo_stack.empty())
    {
        _model->set_slides(_rendo_stack.top().get_state()); 
        _undo_stack.push(_rendo_stack.top());
        _rendo_stack.pop();
    }
    notifyObservers();
};

