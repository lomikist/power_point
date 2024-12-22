#ifndef UNDO_SEM_HPP
#define UNDO_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class UndoSem : public ASemAn
{
protected:
    UndoSem();

    std::unordered_map<std::string, Var_SID> _args;
private:
    void add_count(const std::string& opt, const std::string& arg);
};
}
#endif // UNDO_SEM_HPP

