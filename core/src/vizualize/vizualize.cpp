#include "vizualize.hpp"
#include "controller.hpp"
#include "icanvas.hpp"
#include "logger.hpp"
#include "logger.hpp"
#include "slide.hpp"
#include <exception>
#include <string>

using namespace core;

void Vizualizer::set_model(std::shared_ptr<model::Model> model)
{
    _model = std::move(model); 
};

void Vizualizer::process_slide(std::shared_ptr<core::ICanvas> canvas, int index) 
{
    try {
        model::Page slide = _model->get_slide(index);
        for (auto&& item : slide->get_content())
        {
            if (item->get_atributes().find("-t") == item->get_atributes().end())
                throw std::runtime_error("Core: there is no mentioned type.");

            std::string type = std::get<std::string>(item->get_atributes().at("-t"));
            _shape_creator.create_shape(type, *item)->draw(canvas);
        }
    } catch (std::exception& e)
    {
        core::Controller::get_instance().get_logger()->notify_loggers(e.what());
    }
};

