#ifndef EXIT_COM
#define EXIT_COM

#include "type.hpp"
#include "icommand.hpp"

using namespace cli;

class ExitCom : public ICommand
{
public:
    ExitCom(const CommandInfo& com);
    void execute() override;
private:
    std::unordered_map<std::string, Var_SID> _args;
};
#endif // !EXIT_COM

