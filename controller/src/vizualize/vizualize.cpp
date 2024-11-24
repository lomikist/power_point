#include "vizualize.hpp"
#include "icanvas.hpp"
#include "logger.hpp"
#include "logger.hpp"
#include "slide.hpp"
#include <exception>
#include <string>

using namespace core;

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
        for (const auto& item : slide.get_content())
        {
            std::string type = std::get<std::string>(item.get_atributes().at("-t"));
            _shape_creator.create_shape(type, item)->draw(canvas);
        }
    } catch (std::exception& e)
    {
        core::Logger::get_instance().notify_loggers(e.what());
    }
};

const std::vector<model::Slide>& Vizualizer::get_slides() const
{
    return _model->get_slides();
}

