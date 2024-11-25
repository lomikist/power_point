#ifndef UNDO_COM
#define UNDO_COM
#include "icommand.hpp"

using namespace cli;

class UndoCom : public cli::ICommand
{
public:
    UndoCom();
    void execute() override;
    void process_args(const std::vector<std::string>& tokens) override;
private:
    void add_count(const std::string& arg);
    std::unordered_map<std::string, Var_SID> _args;
    std::map<std::string, F_vs> _options;
};
#endif // !UNDO_COM

