#include "shape_factory.hpp"
#include "item.hpp"
#include "rect_shape.hpp"
#include "circle_shape.hpp"
#include "textbox_shape.hpp"

#include <memory>

using namespace core;

ShapeFactory::ShapeFactory()
{
    register_shape("elipse", [](std::shared_ptr<model::Item>& item)
    {
        return std::make_shared<core::CircleShape>(item);
    });
    register_shape("rect", [](std::shared_ptr<model::Item>& item)
    {
        return std::make_shared<core::RectShape>(item);
    });
    register_shape("textbox", [](std::shared_ptr<model::Item>& item)
    {
        return std::make_shared<core::TextBoxShape>(item);
    });
}

void ShapeFactory::register_shape(const std::string& name, ShapeCreator creator)
{
    creators[name] = std::move(creator);
};

std::shared_ptr<Ishape> ShapeFactory::create_shape(const std::string& name, std::shared_ptr<model::Item>& item)
{
    auto func_it = creators.find(name);
    if (func_it != creators.end())
    {
        return func_it->second(item);
    }
    throw std::runtime_error("Shape not found: " + name);
};

