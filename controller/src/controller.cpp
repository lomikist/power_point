#include "controller.hpp"
#include "add_shape_command.hpp"
#include "add_slide_command.hpp"
#include "command.hpp"
#include "rect_shape.hpp"
#include <memory>

using namespace core;

Controller::Controller()
{
    _parser = std::make_unique<cli::Parser>();
    _model = std::make_unique<model::Model>();
}

Controller::~Controller()
{
};

void Controller::start()
{
    _parser->add_observer(shared_from_this());
    
    std::string current_str;
    while (true)
    {
        std::getline(std::cin, current_str);
        _parser->start(current_str);
    }   
};

int convertStringToInt(const std::string& str) {
    // Check if the entire string is numeric (optional support for negative sign)
    if (str.empty() || (!std::all_of(str.begin(), str.end(), ::isdigit) && 
        !(str[0] == '-' && std::all_of(str.begin() + 1, str.end(), ::isdigit)))) {
        throw std::runtime_error("CORE: NON NUMERIC STRING ENCOUNTERED.");
    }
    return std::stoi(str);
}

void Controller::update_cli(const std::shared_ptr<cli::Command>& cmd)
{
    auto slide_command = std::dynamic_pointer_cast<cli::AddSlideCommand>(cmd);
    auto shape_command = std::dynamic_pointer_cast<cli::AddShapeCommand>(cmd);

    if (slide_command)
    {
        _model->add_slide(std::make_shared<model::Slide>(cmd->_args["-n"], convertStringToInt(cmd->_args["-i"])));
    }
    else if (shape_command)//only for rect 
    {
        int index = convertStringToInt(cmd->_args["-i"]);
        int x = convertStringToInt(cmd->_args["-x"]);
        int y = convertStringToInt(cmd->_args["-y"]);
        int w = convertStringToInt(cmd->_args["-w"]);
        int h = convertStringToInt(cmd->_args["-h"]);
        _model->_slides[index]->add_shape(std::make_shared<model::RectShape>(x, y, w, h));
    }
};


