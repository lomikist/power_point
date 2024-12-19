#ifndef COMMAND_FACTORY
#define COMMAND_FACTORY

#include <memory>
#include <map>
#include "type.hpp"
#include "icommand.hpp"

namespace cli
{
class CommandFactory
{
public:
    void                        register_func(std::string command, std::string subcommand, CommandCreatorFun); 
    void                        register_func(std::string command, CommandCreatorFun fun);
    std::shared_ptr<ICommand>   create(const CommandInfo& command_name);
private:
    std::map<std::string, CommandCreatorFun> _command_map;
};
}
#endif // !COMMAND_FACTORY
