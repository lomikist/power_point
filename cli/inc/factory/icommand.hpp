#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP
#include <unordered_map>
#include <vector>
#include <string>

namespace cli 
{
class ICommand 
{ 
public:
    ~ICommand() = default;
    virtual void execute(const std::vector<std::string>&) = 0;
public:
    std::unordered_map<std::string, std::string> _args_to_pass;
};
}
#endif // !ICOMMAND_HPP

