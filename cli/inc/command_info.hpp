#ifndef COMMAND_INFO_HPP
#define COMMAND_INFO_HPP
#include <string>
#include <unordered_map>

namespace cli 

{
using RawArguments = std::unordered_map<std::string, std::string>;

struct CommandInfo 
{
    std::string     _command_name;
    std::string     _subcommand_name;
    RawArguments    _arguments;
};
};
#endif
