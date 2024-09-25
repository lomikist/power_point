#ifndef MODEL_HPP
#define MODEL_HPP
#include <memory>
#include <vector>
#include "slide.hpp"
namespace model
{
class Model
{
public:
    std::vector<std::shared_ptr<Slide>> _slides;
    void add_slide(std::shared_ptr<Slide> new_slide);
    void remove_slide(int index);
};
};
#endif //  MODEL_HPP
