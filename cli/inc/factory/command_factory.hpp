#ifndef COMMAND_FACTORY
#define COMMAND_FACTORY
#include <functional>
#include <memory>
#include <map>
#include <string>
#include "add_slide_com.hpp"
#include "icommand.hpp"

namespace cli
{
using CommandCreatorFun = std::function<std::shared_ptr<ICommand>()>;

class CommandFactory
{
public:
    void                        register_func(std::string command, std::string subcommand, CommandCreatorFun); 
    void                        register_func(std::string command, CommandCreatorFun fun);
    std::shared_ptr<ICommand>   create(std::string command, std::string subcom);
    std::shared_ptr<ICommand>   create(std::string command);
private:
    std::map<std::string, CommandCreatorFun> _command_map;
};
}
#endif // !COMMAND_FACTORY
