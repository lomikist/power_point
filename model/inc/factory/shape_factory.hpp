#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include "shape.hpp"
#include "rect_shape.hpp"
#include "circle_shape.hpp"
#include <memory>
#include <unordered_map>
#include <variant> 

namespace model
{
class ShapeFactory
{
public:
    static std::shared_ptr<IShape> create_shape(const std::unordered_map<std::string, std::variant<std::string, int, double>>& options); 
};
};
#endif //  SHAPE_FACTORY_HPP
