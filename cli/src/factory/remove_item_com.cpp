#include "remove_item_com.hpp"
#include "parser.hpp"
#include "editor.hpp"
#include "remove_item_action.hpp"
#include <memory>
#include <stdexcept>

using namespace cli;

RemoveItemCom::RemoveItemCom()
{
    _options["-id"] = [this](const std::string& opt, const std::string& args){
        add_id(opt, args); 
    };
    _options["-i"] = [this](const std::string& opt, const std::string& args){
        add_index(opt, args); 
    };
};

void RemoveItemCom::execute()
{
    /*std::cout << "exec removitem" << std::endl;*/
    int item_id = std::get<int>(_args["-id"]);
    int slide_index = std::get<int>(_args["-i"]);

    auto remove_action = std::make_shared<core::RemoveItemAction>(slide_index, item_id);
    core::Editor::get_instance().process_action(remove_action);
};

void RemoveItemCom::add_id(const std::string& opt, const std::string& args)
{
    int id = Parser::str_to_int(args);
    _args[opt] = id;
};

void RemoveItemCom::add_index(const std::string& opt, const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args[opt] = index;
};

