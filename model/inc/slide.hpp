#ifndef SLIDE_HPP 
#define SLIDE_HPP 
#include <memory>
#include <vector>
#include <string>
#include "shape.hpp"
namespace model
{
class Slide 
{
public:
    Slide(const std::string& title, int index)
    {
        _title = title;
        _index = index;
    };
    int _index;
    std::string _title;
    std::vector<std::shared_ptr<Shape>> _shapes;
    void add_shape(std::shared_ptr<Shape> shape)
    {
        _shapes.push_back(shape);
    };
private:
    void set_index(int index)
    {
        _index = index;
    }
};
}

#endif //  SLIDE_HPP!
