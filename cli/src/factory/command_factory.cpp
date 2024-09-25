#include "command_factory.hpp"
#include "command.hpp"
#include <string>
using namespace cli;
void CommandFactory::register_func(std::string command, std::string subcommand, CommandCreatorFun creator)
{
    commandMap[command + " " + subcommand] = creator;
};

std::shared_ptr<Command> CommandFactory::create(std::string command, std::string subcommand)
{
    auto key = command + " " + subcommand;
    if (commandMap.find(key) != commandMap.end()) {
        return commandMap[key]();
    }
    return nullptr;
}
