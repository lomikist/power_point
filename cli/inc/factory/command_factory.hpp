#ifndef COMMAND_FACTORY
#define COMMAND_FACTORY
#include <functional>
#include <memory>
#include <map>
#include <string>
#include "add_shape_command.hpp"
#include "add_slide_command.hpp"
#include "command.hpp"
namespace cli
{
class CommandFactory
{
public:
    using CommandCreatorFun = std::function<std::shared_ptr<Command>()>;
    void register_func(std::string command, std::string subcommand, CommandCreatorFun); 
    std::shared_ptr<Command> create(std::string command, std::string subcommand);
private:
    std::map<std::string, CommandCreatorFun> commandMap;
};
}
#endif // !COMMAND_FACTORY
