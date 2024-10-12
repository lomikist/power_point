#include "editor.hpp"
#include "rect_shape.hpp"
#include "shape_factory.hpp"
#include <memory>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

using namespace core;

Editor::Editor()
{
};

Editor::~Editor()
{
};

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
    
    if (index > _model->_slides.size() || index < 1)
        throw std::runtime_error("EDITOR: Enter valid index.");

    _model->_slides[index - 1]->add_shape(model::ShapeFactory::create_shape(options));
};

void Editor::add_slide(int index, const std::string& name)
{
    if (_model && index == -1)// for inderting in the end     
        _model->add_slide(std::make_shared<model::Slide>(name, _model->_slides.size()));
    else 
        _model->add_slide(std::make_shared<model::Slide>(name, index));
};

void Editor::remove_shape(int slide_index, int shape_index){
    if (slide_index < 0 &&
        slide_index >= _model->_slides.size() && 
        shape_index >= _model->_slides[slide_index - 1]->_shapes.size())
        throw std::runtime_error("CLI: not valid index");
    else
        _model->_slides[slide_index]->remove_shape(shape_index);
};

void Editor::remove_slide(int slide_index){
    if (slide_index < 0 &&
        slide_index >= _model->_slides.size())
        throw std::runtime_error("CLI: not valid index");
    else
        _model->remove_slide(slide_index);
};