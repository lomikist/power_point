#ifndef RENDO_COM
#define RENDO_COM
#include "icommand.hpp"

using namespace cli;

class RendoCom : public cli::ICommand
{
public:
    RendoCom();
    void execute() override;
    void process_args(const std::vector<std::string>& tokens) override;
private:
    void add_count(const std::string& arg);
    std::unordered_map<std::string, Var_SID> _args;
    std::map<std::string, F_vs> _options;
};
#endif // !RENDO_COM

