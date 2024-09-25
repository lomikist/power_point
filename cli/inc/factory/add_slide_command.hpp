#ifndef ADD_SLIDE_COMMAND_HPP
#define ADD_SLIDE_COMMAND_HPP
#include <map>
#include <vector>
#include <functional>
#include "command.hpp"

namespace cli 
{
class AddSlideCommand : public Command
{
public:
    AddSlideCommand();
    ~AddSlideCommand() = default;
    void execute(const std::vector<std::string>& tokens) override; 
private:
    void add_title(const std::vector<std::string>& args);
    void add_index(const std::vector<std::string>& args);
    void register_options();
    std::map<std::string, std::function<void(const std::vector<std::string>&)>> _options;
};
}
#endif // !ADD_SLIDE_COMMAND_HPP
