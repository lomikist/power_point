#ifndef SHOW_SLIDE_COM_HPP
#define SHOW_SLIDE_COM_HPP

#include "icommand.hpp"
#include "show_slid_sem.hpp"
#include "type.hpp"

namespace cli 
{
class ShowSlideCom : public ICommand 
{
public:
    ShowSlideCom(const CommandInfo& com);
    ~ShowSlideCom() = default;
    void execute() override; 

    ShowSlideSem    _sem_analizer;  
};
}
#endif // !SHOW_SLIDE_COM_HPP

