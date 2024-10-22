#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>

namespace cli 
{
class ICommand 
{ 
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    virtual void process_args(const std::vector<std::string>&) = 0;
public:
    std::unordered_map<std::string, std::variant<std::string, int, double>> _args;
};
}
#endif // !ICOMMAND_HPP

