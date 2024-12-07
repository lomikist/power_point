#ifndef REMOVESLIDE_ACTION_HPP
#define REMOVESLIDE_ACTION_HPP

#include "iaction.hpp"
#include "slide.hpp"
#include <memory>
namespace core 
{
class RemoveSlideAction : public Iaction
{
public:
    RemoveSlideAction(int index);
    std::shared_ptr<Iaction> do_action(std::shared_ptr<model::Model> model) override; 
private:
    int _current_slide_index; 
};
}
#endif // !REMOVESLIDE_ACTION_HPP
