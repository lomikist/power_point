#ifndef UNDO_COM
#define UNDO_COM

#include "icommand.hpp"
#include "type.hpp"
#include "undo_sem.hpp"

using namespace cli;

class UndoCom : public ICommand, public UndoSem
{
public:
    UndoCom(const CommandInfo& com);
    void execute() override;
};
#endif // !UNDO_COM

