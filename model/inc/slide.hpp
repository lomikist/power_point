#ifndef SLIDE_HPP 
#define SLIDE_HPP 
#include <memory>
#include <ostream>
#include <vector>
#include <string>
#include "shape.hpp"
#include <iostream>
namespace model
{
class Slide 
{
public:
    Slide(const std::string& title, int index);
    int _index;
    std::string _title;
    std::vector<std::shared_ptr<IShape>> _shapes;
    void add_shape(std::shared_ptr<IShape> shape);

    friend std::ostream& operator<<(std::ostream& os, const Slide& slide)
    {
        os << "Slide title: " << slide._title << ", Index: " << slide._index << std::endl;
        os << "slide size" << slide._shapes.size() << std::endl;
        for (auto&& shape : slide._shapes) {
            shape->print(os);
        }
        std::cout << std::endl;
        return os;
    };
private:
    void set_index(int index);
};
}

#endif //  SLIDE_HPP!
