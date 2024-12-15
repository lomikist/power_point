#include "command_factory.hpp"

using namespace cli;

void CommandFactory::register_func(std::string command, std::string subcom, CommandCreatorFun fun)
{
    _command_map[command + subcom] = fun; 
};

void CommandFactory::register_func(std::string command, CommandCreatorFun fun)
{
    _command_map[command] = fun; 
};

std::shared_ptr<Acommand> CommandFactory::create(const std::string& command_name)
{
    if (_command_map.find(command_name) != _command_map.end())
    {
        return _command_map[command_name]();
    }
    return nullptr;
};

