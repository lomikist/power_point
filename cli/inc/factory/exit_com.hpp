#ifndef EXIT_COM
#define EXIT_COM
#include "icommand.hpp"

using namespace cli;

class ExitCom : public cli::ICommand
{
public:
    ExitCom();
    void execute() override;
    void process_args(const std::vector<std::string>& tokens) override {};
private:
    std::unordered_map<std::string, Var_SID> _args;
};
#endif // !EXIT_COM

