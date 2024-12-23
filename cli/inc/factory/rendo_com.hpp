#ifndef RENDO_COM
#define RENDO_COM

#include "icommand.hpp"
#include "rendo_sem.hpp"
#include "type.hpp"

using namespace cli;

class RendoCom : public ICommand
{
public:
    RendoCom(const CommandInfo& com);
    void execute() override;
    
    RendoSem _sem_analizer;
};
#endif // !RENDO_COM

