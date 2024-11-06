#include "model.hpp"
#include <memory>
#include <stdexcept>

using namespace model;

void Model::add_slide(std::shared_ptr<Slide> new_slide, int index)
{
    if (index == -1 || index > _slides.size())
    {
        _slides.push_back(new_slide);
    } else if (index < -1)
    {
        throw std::runtime_error("Model: index can't be a less then -1");
    } else 
    {
        _slides.insert(_slides.begin() + index, new_slide);
    }
};

void Model::remove_slide(int index)
{
    _slides.erase(_slides.begin() + index);
    std::cout << "Slide N " << index << " is removed.";
};

std::shared_ptr<Slide> Model::get_slide(int index) const
{
    if (index >= 0 && index < _slides.size())
        return _slides[index];
    throw std::runtime_error("Model: can't get slide");
}

const std::vector<std::shared_ptr<Slide>>& Model::get_slides() const
{
    if (_slides.empty())
        throw std::runtime_error("Model: slide is empty");
    return _slides;
};

