#include "model.hpp"
#include <memory>
#include <stdexcept>

using namespace model;

void Model::add_slide(std::shared_ptr<Slide> new_slide)
{
    if (new_slide->_index == -1)
    {
        _slides.push_back(new_slide);
        new_slide->_index = _slides.size();
    }
    else if (new_slide->_index > _slides.size() || new_slide->_index < 0)
    {
        throw std::runtime_error("MODEL: not valid index.");
    }
    else 
        _slides.insert(_slides.begin() + new_slide->_index, new_slide);
};

void Model::remove_slide(int index)
{
    std::cout << "removing slide with index \n" << index << std::endl; 
};

std::shared_ptr<Slide> Model::get_slide(int index) const
{
    if (index >= 0 && index < _slides.size())
        return _slides[index];
    throw std::runtime_error("Model: can't get slide");
}

