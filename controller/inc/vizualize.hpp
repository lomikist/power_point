#ifndef VIZUALIZER_HPP
#define VIZUALIZER_HPP
#include <memory>
#include <ostream>
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
    void print(std::ostream& os, int index);
    void set_model(std::shared_ptr<model::Model> model); 
};
}
#endif //! VIZUALIZER_HPP
