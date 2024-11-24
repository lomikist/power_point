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
    std::vector<Slide> _slides;
public:
    void add_slide(const Slide& new_slide, int index);
    void remove_slide(int index);
    const Slide& get_slide(int index) const;
    const std::vector<Slide>& get_slides() const;
    Slide& get_slide(int index);
    std::vector<Slide>& get_slides();
    void set_slides(const std::vector<Slide>& slides);
};

class ModelMemento 
{
private:
    std::vector<Slide> _slides_state;
public:
    ModelMemento(const std::vector<Slide>& state);
    const std::vector<Slide>& get_state() const;
};
};
#endif //  MODEL_HPP
