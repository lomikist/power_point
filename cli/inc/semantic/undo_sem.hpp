#ifndef UNDO_SEM_HPP
#define UNDO_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class UndoSem : public ASemAn
{
public:
    UndoSem();

    Atributes get_args();
private:
    Atributes _args;
    void add_count(const std::string& opt, const std::string& arg);
};
}
#endif // UNDO_SEM_HPP

