#ifndef RUN_COM_HPP
#define RUN_COM_HPP

#include "icommand.hpp"
#include "run_sem.hpp"
#include "type.hpp"

namespace cli 
{
class RunCom : public ICommand 
{ 
public:
    RunCom(const CommandInfo& com);
    ~RunCom() = default;
    void execute() override;
    RunSem _sem_analizer;
};

}
#endif // !RUN_COM_HPP

