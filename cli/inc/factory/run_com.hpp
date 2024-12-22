#ifndef RUN_COM_HPP
#define RUN_COM_HPP

#include "icommand.hpp"
#include "run_sem.hpp"
#include "type.hpp"

namespace cli 
{
class RunCom : public ICommand, public RunSem
{ 
public:
    RunCom(const CommandInfo& com);
    ~RunCom() = default;
    void execute() override;
};

}
#endif // !RUN_COM_HPP

