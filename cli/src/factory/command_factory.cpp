#include "command_factory.hpp"
#include "type.hpp"

using namespace cli;

void CommandFactory::register_func(std::string command, std::string subcom, CommandCreatorFun fun)
{
    _command_map[command + subcom] = fun; 
};

void CommandFactory::register_func(std::string command, CommandCreatorFun fun)
{
    _command_map[command] = fun; 
};

std::shared_ptr<ICommand> CommandFactory::create(const CommandInfo& command_info)
{
    auto full_name = command_info._command_name + command_info._subcommand_name;
    if (_command_map.find(full_name) != _command_map.end())
    {
        return _command_map[full_name](command_info);
    }
    return nullptr;
};

