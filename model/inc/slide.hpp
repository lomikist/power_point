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
    std::vector<std::shared_ptr<AShape>> _shapes;
    void add_shape(std::shared_ptr<AShape> shape);
    void remove_shape(int index); 
private:
    void set_index(int index);
};
}

#endif //  SLIDE_HPP!
