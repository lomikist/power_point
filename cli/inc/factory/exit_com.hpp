#ifndef EXIT_COM
#define EXIT_COM
#include "command_factory.hpp"
#include "icommand.hpp"

using namespace cli;

class ExitCom : public cli::Acommand
{
public:
    ExitCom();
    void execute() override;
    /*void process_args(const CommandInfo& com_info) override;*/
private:
    std::unordered_map<std::string, Var_SID> _args;
};
#endif // !EXIT_COM

