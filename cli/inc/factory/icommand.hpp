#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP
#include "command_info.hpp"
#include <stdexcept>
#include <variant>
#include <vector>
#include <string>
#include <functional>
#include <map>

namespace cli 
{

using Var_SID = std::variant<std::string, int, double>;
using F_vs = std::function<void(const std::string& option, const std::string& str)>;
using Valid_types = std::map<std::string, std::vector<std::string>>;

class ICommand 
{ 
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

class Acommand : public ICommand
{
public:
    virtual void process_args(const CommandInfo& com_info)
    {
        for (auto&& opt : com_info._arguments)
        {
            if (_options.find(opt.first) != _options.end())
            {
                _options[opt.first](opt.first, opt.second);
            } else 
            {
                throw std::runtime_error("CLI: OPTION NOT FOUND:" + opt.first);
            }
        }
    };
    virtual void execute() = 0;
protected:
    std::map<std::string, F_vs> _options;
};

}
#endif // !ICOMMAND_HPP

