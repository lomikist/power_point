#include "controller.hpp"
using namespace core;

Controller::Controller()
{
    _parser = std::make_shared<cli::Parser>();
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
