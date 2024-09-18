#include "controller.hpp"

Controller::Controller()
{
    _parser = std::make_shared<CLI::Parser>();
};

Controller::~Controller(){

};

void Controller::start()
{
    std::string current_str;
    while (true)
    {
        std::getline(std::cin, current_str);
        _parser->start(current_str);
    }   
};
