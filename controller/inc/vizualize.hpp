#ifndef VIZUALIZER_HPP
#define VIZUALIZER_HPP
#include <memory>
#include <ostream>
#include "icanvas.hpp"
#include "model.hpp"
#include "slide.hpp"

namespace core 
{
class Vizualizer 
{
private:
    Vizualizer();
    Vizualizer(const Vizualizer&);
    std::shared_ptr<model::Model> _model;
public:
    ~Vizualizer();
    static Vizualizer& get_instance();
    void process_slide(std::shared_ptr<core::ICanvas> canvas, int index);
    void set_model(std::shared_ptr<model::Model> model); 
};
}
#endif //! VIZUALIZER_HPP
