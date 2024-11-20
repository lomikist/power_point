#ifndef RUN_COM_HPP
#define RUN_COM_HPP
#include "icommand.hpp"
#include <functional>
#include <map>
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>

namespace cli 
{

class RunCom : public ICommand 
{ 
public:
    RunCom();
    ~RunCom() = default;
    void execute() override;
    void process_args(const std::vector<std::string>&) override;
    void add_path(const std::string& path); 
private:
    void register_options();
    std::unordered_map<std::string, Var_SID> _args;
    std::map<std::string, F_vs> _options;
};

}
#endif // !RUN_COM_HPP

