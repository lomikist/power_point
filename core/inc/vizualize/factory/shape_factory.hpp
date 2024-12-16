#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include "ashape.hpp"
#include <functional>

namespace core
{
class ShapeFactory
{
public:
    using ShapeCreator = std::function<std::shared_ptr<Ashape>(const model::Item& item)>;

    ShapeFactory();
    void register_shape(const std::string& name, ShapeCreator creator);
    std::shared_ptr<Ishape> create_shape(const std::string& name, const model::Item& item);
private:
    std::unordered_map<std::string, ShapeCreator> creators;
};
}

#endif // !SHAPE_FACTORY_HPP
