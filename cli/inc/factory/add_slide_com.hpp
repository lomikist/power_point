#ifndef ADD_SLIDE_COM_HPP
#define ADD_SLIDE_COM_HPP

#include "add_slide_sem.hpp"

namespace cli 
{
class AddSlideCom : public ICommand 
{
public:
    AddSlideCom(const CommandInfo& com);
    ~AddSlideCom() = default;
    void execute() override; 

    AddSlideSem _sem_analizer;
};
}
#endif // !ADD_SLIDE_COM_HPP

