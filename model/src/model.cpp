#include "model.hpp"
#include <memory>
#include <stdexcept>

using namespace model;

void Model::add_slide(const Slide& new_slide, int index)
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
}

void Model::remove_slide(int index)
{
    _slides.erase(_slides.begin() + index);
    std::cout << "Slide N " << index << " is removed.";
}

const Slide& Model::get_slide(int index) const
{
    if (index >= 0 && index < _slides.size())
        return _slides[index];
    throw std::runtime_error("Model: can't get slide");
}

Slide& Model::get_slide(int index)
{
    return const_cast<Slide&>(static_cast<const Model&>(*this).get_slide(index));
}

const std::vector<Slide>& Model::get_slides() const
{
    if (_slides.empty())
        throw std::runtime_error("Model: slide is empty");
    return _slides;
}

std::vector<Slide>& Model::get_slides()
{
    return const_cast<std::vector<Slide>&>(static_cast<const Model&>(*this).get_slides());
}

void Model::set_slides(const std::vector<Slide>& slides)
{
    _slides = slides;
}
//////////////////////////////////////////////// memento

ModelMemento::ModelMemento(const std::vector<Slide>& state) : _slides_state(state)
{}

const std::vector<Slide>& ModelMemento::get_state() const
{
    return _slides_state;
}

