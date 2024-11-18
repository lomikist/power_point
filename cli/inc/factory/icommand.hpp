#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>
#include <functional>
#include <map>

namespace cli 
{
using Var_SID = std::variant<std::string, int, double>;
using F_vs = std::function<void(const std::string& str)>;
using Valid_types = std::map<std::string, std::vector<std::string>>;

class ICommand 
{ 
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    virtual void process_args(const std::vector<std::string>&) = 0;
};
}
#endif // !ICOMMAND_HPP

