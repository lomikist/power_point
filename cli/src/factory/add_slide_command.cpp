#include "add_slide_command.hpp"
#include <iostream>

void AddSlideCommand::execute(const std::vector<std::string>& tokens)
{
    for (auto&& token : tokens) {
        std::cout << token << std::endl;
    }    
};
