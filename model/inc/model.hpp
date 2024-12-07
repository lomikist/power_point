#ifndef MODEL_HPP
#define MODEL_HPP
#include <memory>
#include <vector>
#include "slide.hpp"
namespace model
{

using Page = std::shared_ptr<Slide>;

class Model
{
public:
    std::vector<Page> get_slides() const;
    void              add_slide(Page new_slide, int index);
    void              remove_slide(int index);
    Page              get_slide(int index) const;
    Page              get_slide_by_ID(int id) const;
    void              set_slides(std::vector<Page> slides);
private:
    std::vector<Page> _slides;
};
};
#endif //  MODEL_HPP
