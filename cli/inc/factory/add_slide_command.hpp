#ifndef ADD_SLIDE_COMMAND_HPP
#define ADD_SLIDE_COMMAND_HPP
#include "command.hpp"

class AddSlideCommand : public Command
{
public:
    void execute(const std::vector<std::string>& tokens) override; 
    ~AddSlideCommand() = default;
private:
};

#endif // !ADD_SLIDE_COMMAND_HPP
