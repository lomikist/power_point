#ifndef UNDO_COM
#define UNDO_COM
#include "command_factory.hpp"
#include "icommand.hpp"

using namespace cli;

class UndoCom : public Acommand
{
public:
    UndoCom();
    void execute() override;
    /*void process_args(const CommandInfo& com_info) override;*/
private:
    void add_count(const std::string& opt, const std::string& arg);
    std::unordered_map<std::string, Var_SID> _args;
};
#endif // !UNDO_COM

