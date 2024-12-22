#ifndef REMOVE_SLIDE_SEM_HPP
#define REMOVE_SLIDE_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class RemoveSlideSem : public ASemAn
{
protected:
    RemoveSlideSem();

    std::unordered_map<std::string, Var_SID> _args;
private:
    void add_id(const std::string& opt, const std::string& args);
    void add_index(const std::string& opt, const std::string& args);
};
}
#endif // REMOVE_SLIDE_SEM_HPP  
