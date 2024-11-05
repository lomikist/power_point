#include "vizualize.hpp"
#include "circle_shape.hpp"
#include "icanvas.hpp"
#include "slide.hpp"
#include <exception>

using namespace core;

Vizualizer::Vizualizer()
{
};

Vizualizer::~Vizualizer()
{
};

Vizualizer& Vizualizer::get_instance()
{
    static Vizualizer instance;
    return instance;
};

void Vizualizer::set_model(std::shared_ptr<model::Model> model)
{
    _model = std::move(model); 
};

void Vizualizer::process_slide(std::shared_ptr<core::ICanvas> canvas, int index)
{
    try {
        auto slide = _model->get_slide(index);
        for (const auto& shape : slide->get_content())
        {
            auto circle_shape = std::dynamic_pointer_cast<model::CircleShape>(shape);
            auto rect_shape = std::dynamic_pointer_cast<model::RectShape>(shape);
             
            if (circle_shape)
                canvas->draw(circle_shape);
            else if (rect_shape)
                canvas->draw(rect_shape);
        };
    } catch(std::exception& e){
        std::cout << e.what();
    }
};

