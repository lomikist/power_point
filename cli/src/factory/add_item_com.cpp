#include "add_item_com.hpp"
#include "add_item_action.hpp"
#include "controller.hpp"
#include "editor.hpp"
#include "item.hpp"
#include <cctype>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace cli;

const Valid_types AddItemCom::s_valid_shape_atributes {
                                            {"rect" , {"-c", "-i", "-t"}},
                                            {"textbox", {"-c", "-i", "-t","-content"}},
                                            {"elipse", {"-c", "-i", "-t" }}
                                        }; 

const std::vector<std::string> AddItemCom::s_valid_geometry = {"-x", "-y", "-w", "-h"};

AddItemCom::AddItemCom(const CommandInfo& com) : 
            AddItemSem()
{
    process_args(com._arguments);
};

void AddItemCom::execute()
{
    std::string type = std::get<std::string>(_atributes.at("-t"));
    int slide_index = std::get<int>(_atributes.at("-i"));
    int x = std::get<int>(_geometery.at("-x"));
    int y = std::get<int>(_geometery.at("-y"));
    int w = std::get<int>(_geometery.at("-w"));
    int h = std::get<int>(_geometery.at("-h"));
     
    if (AddItemSem::if_not_contain(s_valid_shape_atributes.at(type), _atributes))
        throw std::runtime_error("Cli: some atrubutes not setted look documentation.");
    else if (AddItemSem::if_not_contain(s_valid_geometry, _geometery)) 
        throw std::runtime_error("Cli: some geometery element not setted look documentation.");

    auto action = std::make_shared<core::AddItemAction>(
        std::make_shared<model::Item>(x, y, w, h, _atributes),
            slide_index
        );
    
    core::Controller::get_instance().get_editor()->process_action(action);
};

