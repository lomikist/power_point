#ifndef REMOVE_SLIDE_COM_HPP
#define REMOVE_SLIDE_COM_HPP

#include "icommand.hpp"
#include "remove_slide_sem.hpp"
#include "type.hpp"

namespace cli 
{
class RemoveSlideCom : public ICommand, public RemoveSlideSem 
{
public:
    RemoveSlideCom(const CommandInfo& com);
    ~RemoveSlideCom() = default;
    void execute() override; 
};
}
#endif // !REMOVE_SLIDE_COM_HPP

