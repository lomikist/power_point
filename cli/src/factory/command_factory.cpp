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

std::shared_ptr<ICommand>   CommandFactory::create(std::string command, std::string subcom)
{
    auto key = command + subcom;
    if (_command_map.find(key) != _command_map.end())
        return _command_map[key]();

    return nullptr;
};

std::shared_ptr<ICommand>   CommandFactory::create(std::string command)
{
    if (_command_map.find(command) != _command_map.end())
        return _command_map[command]();

    return nullptr;
};
