#ifndef ADDSLIDE_ACTION_HPP
#define ADDSLIDE_ACTION_HPP

#include "iaction.hpp"
#include "model.hpp"
#include <memory>
namespace core 
{
class AddSlideAction : public Iaction
{
public:
    AddSlideAction(model::Page slide, int index);
    std::shared_ptr<Iaction> do_action(std::shared_ptr<model::Model> model) override; 
private:
    model::Page _current_slide; 
    int         _index;
};
}
#endif // !ADDSLIDE_ACTION_HPP
