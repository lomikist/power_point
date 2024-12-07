#include "remove_slide_com.hpp"
#include "editor.hpp"
#include "parser.hpp"
#include "remove_slide_action.hpp"
#include <memory>
#include <stdexcept>

using namespace cli;

RemoveSlideCom::RemoveSlideCom()
{
    _options["-i"] = [this](const std::string& args){
        add_index(args); 
    };
    _options["-id"] = [this](const std::string& args){
        add_id(args); 
    };
};

void RemoveSlideCom::process_args(const std::vector<std::string>& tokens)
{
    //TODO if not zugy pawol
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

void RemoveSlideCom::execute()
{
    int id = std::get<int>(_args["-i"]);

    auto remove_act = std::make_shared<core::RemoveSlideAction>(id);
    core::Editor::get_instance().process_action(remove_act);
};

void RemoveSlideCom::add_id(const std::string& args)
{
    _args["-id"] = args;
};

void RemoveSlideCom::add_index(const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args["-i"] = index;
};

