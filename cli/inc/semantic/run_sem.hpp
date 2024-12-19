#ifndef RUN_SEM_HPP
#define RUN_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class RunSem : public ASemAn
{
protected:
    RunSem();

    std::unordered_map<std::string, Var_SID> _args;
private:
    void add_path(const std::string& opt, const std::string& path); 
};
}
#endif // RUN_SEM_HPP
