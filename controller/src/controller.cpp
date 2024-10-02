#include "controller.hpp"
#include "add_shape_com.hpp"
#include "add_slide_com.hpp"
#include "show_slide_com.hpp"
#include "icommand.hpp"
#include "rect_shape.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>

using namespace core;

int stringToInt(const std::string& str) {
    // Check if the entire string is numeric (optional support for negative sign)
    if (str.empty() || (!std::all_of(str.begin(), str.end(), ::isdigit) && 
        !(str[0] == '-' && std::all_of(str.begin() + 1, str.end(), ::isdigit)))) {
        throw std::runtime_error("CORE: NON NUMERIC STRING ENCOUNTERED.");
    }
    return std::stoi(str);
}

Controller::Controller()
{
    _parser = std::make_unique<cli::Parser>();
    _model = std::make_unique<model::Model>();
}

Controller::~Controller()
{
};

void Controller::visit_cmd(const std::shared_ptr<cli::AddSlideCom>& cmd)
{
    _model->add_slide(std::make_shared<model::Slide>(cmd->_args_to_pass["-n"],
                                                     stringToInt(cmd->_args_to_pass["-i"])));
};

void Controller::visit_cmd(const std::shared_ptr<cli::ShowSlideCom>& cmd)
{
    int index = stringToInt(cmd->_args_to_pass["-i"]);
    std::cout << _model->_slides[index]->_title << " -- ";
    for (auto&& i : _model->_slides[index]->_shapes)
        i->print();
    ;
};

void Controller::visit_cmd(const std::shared_ptr<cli::AddShapeCom>& cmd)
{
    int index = stringToInt(cmd->_args_to_pass["-i"]);
    int x = stringToInt(cmd->_args_to_pass["-x"]);
    int y = stringToInt(cmd->_args_to_pass["-y"]);
    int w = stringToInt(cmd->_args_to_pass["-w"]);
    int h = stringToInt(cmd->_args_to_pass["-h"]);
    if (cmd->_args_to_pass["-t"] == "rect")
    {
        _model->_slides[index]->_shapes.push_back(std::make_shared<model::RectShape>(x, y, w, h));
    }
};

void Controller::start()
{
    while (true)
    {
        try{
            auto cmd = _parser->parse(std::cin);
            auto add_slide_com = std::dynamic_pointer_cast<cli::AddSlideCom>(cmd);
            auto add_shape_com = std::dynamic_pointer_cast<cli::AddShapeCom>(cmd);
            auto show_slide_com = std::dynamic_pointer_cast<cli::ShowSlideCom>(cmd);
            
            if (add_slide_com)
                visit_cmd(add_slide_com);
            else if (add_shape_com)
                visit_cmd(add_shape_com);
            else if (show_slide_com)
                visit_cmd(show_slide_com);
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        };
    }   
};

