#ifndef ACOMMAND_HPP
#define ACOMMAND_HPP
#include <unordered_map>
#include <vector>
#include <string>
namespace cli 
{
class Command 
{ 
public:
    ~Command() = default;
    virtual void execute(const std::vector<std::string>&) = 0;
public:
    std::unordered_map<std::string, std::string> _args;
};
}
#endif // !ACOMMAND_HPP

