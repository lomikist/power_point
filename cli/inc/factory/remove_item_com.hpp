#ifndef REMOVE_ITEM_COM_HPP
#define REMOVE_ITEM_COM_HPP

#include "icommand.hpp"
#include "remove_item_sem.hpp"
#include "type.hpp"

namespace cli 
{
class RemoveItemCom : public ICommand
{
public:
    RemoveItemCom(const CommandInfo& com);
    ~RemoveItemCom() = default;
    void execute() override; 
    
    RemoveItemSem _sem_analizer;
};
}
#endif // !REMOVE_ITEM_COM_HPP

