#include "shape_factory.hpp"
#include "circle_shape.hpp"
#include "shape.hpp"
#include <memory>
#include <stdexcept>

using namespace model;

std::shared_ptr<AShape> ShapeFactory::create_shape(const std::unordered_map<std::string, std::variant<std::string, int, double>>& options)
{
    std::string type = std::get<std::string>(options.at("-t"));
    int         x = std::get<int>(options.at("-x"));
    int         y = std::get<int>(options.at("-y"));

    if (type == "rect") 
    {
        int w = std::get<int>(options.at("-w"));
        int h = std::get<int>(options.at("-h"));
        return std::make_shared<model::RectShape>(x, y, w, h);
    }
    else if (type == "circle") 
    {
        int r = std::get<int>(options.at("-r"));
        return std::make_shared<model::CircleShape>(x, y, r);
    }
    else if (type == "text")
    {}
    else 
        throw std::runtime_error("MODEL: not valid shape.");
};
