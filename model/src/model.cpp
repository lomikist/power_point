#include "model.hpp"
#include <memory>
#include <stdexcept>

using namespace model;

void Model::add_slide(std::shared_ptr<Slide> new_slide)
{
    if (new_slide->_index == _slides.size())
    {
        _slides.push_back(new_slide);
    }
    else if (new_slide->_index > _slides.size())
    {
        throw std::runtime_error("MODEL: not valid index.");
    }
    else 
        _slides.insert(_slides.begin() + new_slide->_index, new_slide);
};

void Model::remove_slide(int index)
{
    std::cout << "removing slide\n"; 
};

