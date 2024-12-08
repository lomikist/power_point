#include "icommand.hpp"
#include <string>
#include <vector>
namespace cli 
{

using Atributes = std::unordered_map<std::string, cli::Var_SID>;

class CommandInfo 
{
public:
    std::string _command_type;
    std::string _subcommand_type;
    Atributes   _arguments;
};
};
