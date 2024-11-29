#ifndef VIZUALIZER_HPP
#define VIZUALIZER_HPP
#include <memory>
#include <ostream>
#include "icanvas.hpp"
#include "model.hpp"
#include "shape_factory.hpp"
#include "slide.hpp"

namespace core 
{
class Vizualizer 
{
public:
    ~Vizualizer(){};
    static Vizualizer& get_instance();
    void process_slide(std::shared_ptr<core::ICanvas> canvas, int index);
    void set_model(std::shared_ptr<model::Model> model); 
    const std::vector<model::Slide>& get_slides() const;
private:
    Vizualizer(){};
    std::shared_ptr<model::Model> _model;
    ShapeFactory _shape_creator;
};
}
#endif //! VIZUALIZER_HPP
