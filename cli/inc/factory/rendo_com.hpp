#ifndef RENDO_COM
#define RENDO_COM

#include "icommand.hpp"
#include "rendo_sem.hpp"
#include "type.hpp"

using namespace cli;

class RendoCom : public ICommand, public RendoSem
{
public:
    RendoCom(const CommandInfo& com);
    void execute() override;
};
#endif // !RENDO_COM

