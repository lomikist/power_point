#ifndef COMMAND_FACTORY
#define COMMAND_FACTORY
#include <functional>
#include <memory>
#include <map>
#include <string>
#include "icommand.hpp"
#include "command_info.hpp"

namespace cli
{

using CommandCreatorFun = std::function<std::shared_ptr<Acommand>()>;

class CommandFactory
{
public:
    void                        register_func(std::string command, std::string subcommand, CommandCreatorFun); 
    void                        register_func(std::string command, CommandCreatorFun fun);
    std::shared_ptr<Acommand>   create(const std::string& command_name);
private:
    std::map<std::string, CommandCreatorFun> _command_map;
};
}
#endif // !COMMAND_FACTORY
