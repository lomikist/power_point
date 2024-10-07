#include "editor.hpp"
#include "rect_shape.hpp"
#include "shape_factory.hpp"
#include <memory>
#include <iostream>
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
    int         index = std::get<int>(options.at("-i"));

    _model->_slides[index]->add_shape(model::ShapeFactory::create_shape(options));
};

void Editor::add_slide(int index, const std::string& name)
{
    if (_model)
        _model->add_slide(std::make_shared<model::Slide>(name, index));
};


