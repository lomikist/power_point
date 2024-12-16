#ifndef RENDO_COM
#define RENDO_COM
#include "command_factory.hpp"
#include "icommand.hpp"

using namespace cli;

class RendoCom : public Acommand
{
public:
    RendoCom();
    void execute() override;
private:
    void add_count(const std::string& opt, const std::string& arg);
    std::unordered_map<std::string, Var_SID> _args;
};
#endif // !RENDO_COM

