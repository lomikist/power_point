#ifndef REMOVE_ITEM_SEM_HPP
#define REMOVE_ITEM_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class RemoveItemSem : public ASemAn
{
public:
    RemoveItemSem();
    
    Atributes get_args();
private:
    Atributes _args;

    void add_id(const std::string& opt, const std::string& args);
    void add_index(const std::string& opt, const std::string& args);
};
}
#endif // REMOVE_ITEM_SEM_HPP  
