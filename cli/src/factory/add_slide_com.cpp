#include "add_slide_com.hpp"
#include "add_slide_action.hpp"
#include "editor.hpp"
#include "parser.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace cli;

AddSlideCom::AddSlideCom()
{
    _options["-n"] = [this](const std::string& args){
        add_title(args); 
    };
    _options["-i"] = [this](const std::string& args)
    {
        add_index(args);
    };
};

void AddSlideCom::execute()
{
    int index;
    std::string name = std::get<std::string>(_args["-n"]);

    if (_args.find("-i") != _args.end())
        index = std::get<int>(_args["-i"]);
    else 
        index = -1;

    auto add_action = std::make_shared<core::AddSlideAction>(std::make_shared<model::Slide>(name), index);
    core::Editor& editot = core::Editor::get_instance();
    editot.process_action(add_action);
};

void AddSlideCom::process_args(const std::vector<std::string>& tokens)
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

void AddSlideCom::add_title(const std::string& args)
{
    _args["-n"] = args;
};

void AddSlideCom::add_index(const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args["-i"] = index;
};
