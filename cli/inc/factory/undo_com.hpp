#ifndef UNDO_COM
#define UNDO_COM
#include "icommand.hpp"

using namespace cli;

class UndoCom : public cli::ICommand
{
public:
    UndoCom();
    void execute() override;
    void process_args(const std::vector<std::string>& tokens) override {};
private:
    std::unordered_map<std::string, Var_SID> _args;
};
#endif // !UNDO_COM

