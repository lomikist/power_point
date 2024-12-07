#include "model.hpp"
#include <algorithm>
#include <memory>
#include <stdexcept>

using namespace model;

void Model::add_slide(Page new_slide, int index)
{
    if (index == -1 || index > _slides.size()){
        _slides.push_back(new_slide);
    } else if (index < -1) {
        throw std::runtime_error("Model: index can't be a less then -1");
    } else {
        _slides.insert(_slides.begin() + index, new_slide);
    }
}

void Model::remove_slide(int index)
{
    _slides.erase(_slides.begin() + index);
}

Page Model::get_slide_by_ID(int id) const 
{
    auto slide = std::find_if(_slides.begin(), _slides.end(), [id](auto&& slide) {
        return slide->get_id() == id; 
    });
    if (slide == _slides.end()){
        throw std::runtime_error("MODEL: no slide with this id");
    }
    return *slide;
};

Page Model::get_slide(int index) const
{
    if (index >= 0 && index < _slides.size()) {
        return _slides[index];
    }
    throw std::runtime_error("Model: can't get slide");
}

std::vector<Page> Model::get_slides() const
{
    return _slides;
}

void Model::set_slides(std::vector<Page> slides)
{
    _slides = slides;
}

