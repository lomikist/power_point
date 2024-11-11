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
};
#endif // !EXIT_COM

