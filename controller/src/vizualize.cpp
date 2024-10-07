#include "vizualize.hpp"
#include "slide.hpp"

using namespace core;

Vizualizer::Vizualizer()
{
};

Vizualizer::~Vizualizer()
{
};

Vizualizer& Vizualizer::get_instance()
{
    static Vizualizer instance;
    return instance;
};

void Vizualizer::set_model(std::shared_ptr<model::Model> model)
{
    _model = std::move(model); 
};


void Vizualizer::print(std::ostream& os, int index)
{
    os << *_model->_slides[index];
};
