#ifndef RENDO_SEM_HPP
#define RENDO_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class RendoSem : public ASemAn
{
protected:
    RendoSem();

    std::unordered_map<std::string, Var_SID> _args;
private:
    void add_count(const std::string& opt, const std::string& arg);
};
}
#endif // RENDO_SEM_HPP
