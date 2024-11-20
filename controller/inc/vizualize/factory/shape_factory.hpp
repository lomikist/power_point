#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include "ishape.hpp"

namespace core
{
class ShapeFactory
{
public:
    using ShapeCreator = std::function<std::shared_ptr<Ishape>(std::shared_ptr<model::Item>& item)>;
    ShapeFactory();
    void register_shape(const std::string& name, ShapeCreator creator);
    std::shared_ptr<Ishape> create_shape(const std::string& name, std::shared_ptr<model::Item>& item);
private:
    std::unordered_map<std::string, ShapeCreator> creators;
};
}

#endif // !SHAPE_FACTORY_HPP
