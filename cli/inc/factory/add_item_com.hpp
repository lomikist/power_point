#ifndef ADD_SHAPE_COM_HPP
#define ADD_SHAPE_COM_HPP

#include "add_item_sem.hpp"

namespace cli 
{
class AddItemCom : public ICommand
{
public:
    AddItemCom(const CommandInfo& com);
    ~AddItemCom() = default;
    void execute() override; 
    AddItemSem _sem_analizer;

    static const Valid_types                s_valid_shape_atributes;
    static const std::vector<std::string>   s_valid_geometry; 
};
}
#endif // !ADD_SHAPE_COM_HPP

