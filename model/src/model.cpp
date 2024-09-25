#include "model.hpp"
#include <memory>

using namespace model;

void Model::add_slide(std::shared_ptr<Slide> new_slide)
{
    _slides.push_back(new_slide);
};

void Model::remove_slide(int index)
{
//TODO 
};

