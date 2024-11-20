#include "editor.hpp"
#include "icommand.hpp"
#include "iobserver.hpp"
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


void Editor::add_item(const std::unordered_map<std::string, cli::Var_SID>& geometery,
                      const std::unordered_map<std::string, cli::Var_SID>& atributes)
{
    int index = std::get<int>(atributes.at("-i"));
    int x = std::get<int>(geometery.at("-x"));
    int y = std::get<int>(geometery.at("-y"));
    int w = std::get<int>(geometery.at("-w"));
    int h = std::get<int>(geometery.at("-h"));

    _model->get_slide(index)->add_item(std::make_shared<model::Item>(x, y, w, h, atributes));
    notifyObservers();
};

void Editor::remove_item(int slide_index, int shape_index)
{
    _model->get_slide(slide_index)->remove_item(shape_index);
    notifyObservers();
};

void Editor::add_slide(int index, const std::string& name)
{
    _model->add_slide(std::make_shared<model::Slide>(name), index);

    notifyObservers();
};

void Editor::remove_slide(int slide_index)
{
    _model->remove_slide(slide_index);
    
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
}; 

////////////////////////

const std::vector<std::shared_ptr<model::Slide>>& Editor::get_slides() const
{
    return _model->get_slides();
}
