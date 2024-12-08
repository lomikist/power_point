#include "remove_item_com.hpp"
#include "parser.hpp"
/*#include "editor.hpp"*/
/*#include "remove_item_action.hpp"*/
#include <memory>
#include <stdexcept>

using namespace cli;

RemoveItemCom::RemoveItemCom()
{
    _options["-id"] = [this](const std::string& args){
        add_id(args); 
    };
    _options["-i"] = [this](const std::string& args){
        add_index(args); 
    };
};

void RemoveItemCom::process_args(const std::vector<std::string>& tokens)
{
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        if (_options.find(tokens[i]) != _options.end())
        {
            std::vector<std::string> args(tokens.begin() + i, tokens.end());
            _options[tokens[i]](tokens[i + 1]);
            i++;
        } else 
        {
            throw std::runtime_error("CLI: OPTION NOT FOUND:" + tokens[i]);
        }
    }    
};

void RemoveItemCom::execute()
{
    std::cout << "exec removitem" << std::endl;
    /*int item_id = std::get<int>(_args["-id"]);*/
    /*int slide_index = std::get<int>(_args["-i"]);*/
    /**/
    /*auto remove_action = std::make_shared<core::RemoveItemAction>(slide_index, item_id);*/
    /*core::Editor::get_instance().process_action(remove_action);*/
};

void RemoveItemCom::add_id(const std::string& args)
{
    int id = Parser::str_to_int(args);
    _args["-id"] = id;
};

void RemoveItemCom::add_index(const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args["-i"] = index;
};

