#ifndef MODEL_HPP
#define MODEL_HPP
#include <memory>
#include <vector>
#include "slide.hpp"
namespace model
{
class Model
{
private:
    std::vector<std::shared_ptr<Slide>> _slides;
public:
    void add_slide(std::shared_ptr<Slide> new_slide, int index);
    void remove_slide(int index);
    std::shared_ptr<Slide> get_slide(int index) const;
    const std::vector<std::shared_ptr<Slide>>& get_slides() const;
};
};
#endif //  MODEL_HPP
