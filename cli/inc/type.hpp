#ifndef TYPE_HPP
#define TYPE_HPP

#include <variant>
#include <functional>
#include <map> 
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "icommand.hpp"
#include "model.hpp"

namespace cli 
{

enum TokenType
{
    START,
    WORD,
    SUBCOM,
    OPT,
    NUM,
    MVAL,
    SCON,
    ECON,
    BADTYPE
};

using RawArguments = std::unordered_map<std::string, std::string>;

struct CommandInfo 
{
    std::string     _command_name;
    std::string     _subcommand_name;
    RawArguments    _arguments;
};

using CommandCreatorFun = std::function<std::shared_ptr<ICommand>(const CommandInfo& com)>;
using Var_SID = std::variant<std::string, int, double, model::RGB>;
using F_vs = std::function<void(const std::string& option, const std::string& str)>;
using Valid_types = std::map<std::string, std::vector<std::string>>;
using ValidStates = std::unordered_map<TokenType, std::unordered_set<TokenType>>;

}
#endif //TYPE_HPP
