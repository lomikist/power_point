#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>
#include <functional>

namespace cli 
{

using Var_SID = std::variant<std::string, int, double>;
using F_vs = std::function<void(const std::string& str)>;

class ICommand 
{ 
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    virtual void process_args(const std::vector<std::string>&) = 0;
public:
    std::unordered_map<std::string, Var_SID> _args;
};
}
#endif // !ICOMMAND_HPP

