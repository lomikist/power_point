#include "editor.hpp"
#include "iobserver.hpp"
#include "shape_factory.hpp"
#include <memory>
#include <string>
#include <unordered_map>

using namespace core;

Editor::Editor()
{};

Editor::~Editor()
{};

Editor& Editor::get_instance()
{
    static Editor _instance;
    return _instance;
};

void Editor::set_model(std::shared_ptr<model::Model> model)
{
    _model = std::move(model); 
};

void Editor::add_shape(const std::unordered_map<std::string, std::variant<std::string, int, double>>& options)
{ 
    int index = std::get<int>(options.at("-i"));
    _model->get_slide(index)->add_shape(model::ShapeFactory::create_shape(options));

    notifyObservers();
};

void Editor::add_slide(int index, const std::string& name)
{
    _model->add_slide(std::make_shared<model::Slide>(name), index);
    notifyObservers();
};

void Editor::remove_shape(int slide_index, int shape_index)
{
    _model->get_slide(slide_index)->remove_shape(shape_index);
};

void Editor::remove_slide(int slide_index)
{
    _model->remove_slide(slide_index);
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
}; 

