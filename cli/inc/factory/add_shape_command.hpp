#ifndef ADD_SHAPE_COMMAND_HPP
#define ADD_SHAPE_COMMAND_HPP
#include "command.hpp"
#include <functional>
#include <string>
#include <map>
#include <vector>

namespace cli 
{
class AddShapeCommand : public Command
{
public:
    AddShapeCommand();
    void execute(const std::vector<std::string>& tokens) override; 
    ~AddShapeCommand() = default;
    
private:
    void register_options();
    void add_circle(const std::vector<std::string>& tokens);
    void add_rect(const std::vector<std::string>& tokens);
    std::map<std::string, std::function<void(const std::vector<std::string>&)>> _options;
};
}
#endif // !ADD_SHAPE_COMMAND_HPP
