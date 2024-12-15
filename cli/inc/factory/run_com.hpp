#ifndef RUN_COM_HPP
#define RUN_COM_HPP
#include "command_factory.hpp"
#include "icommand.hpp"
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

namespace cli 
{

class RunCom : public Acommand 
{ 
public:
    RunCom();
    ~RunCom() = default;
    void execute() override;
    /*void process_args(const CommandInfo& com_info) override;*/
    void add_path(const std::string& , const std::string& path); 
private:
    void register_options();
    std::unordered_map<std::string, Var_SID> _args;
};

}
#endif // !RUN_COM_HPP

