#ifndef UNDO_COM
#define UNDO_COM

#include "icommand.hpp"
#include "type.hpp"
#include "undo_sem.hpp"

using namespace cli;

class UndoCom : public ICommand 
{
public:
    UndoCom(const CommandInfo& com);
    void execute() override;

    UndoSem _sem_analizer;
};
#endif // !UNDO_COM

