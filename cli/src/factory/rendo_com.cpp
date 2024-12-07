#include "rendo_com.hpp"
#include "editor.hpp"
#include "parser.hpp"

using namespace cli;

void RendoCom::execute()
{
    int count;
    if (_args.find("-n") != _args.end())
        count = std::get<int>(_args["-n"]);
    else 
        count = 1;
    while (count > 0)
    {
        core::Editor::get_instance().rendo_action();
        count--;
    }
};

RendoCom::RendoCom()
{
    _options["-n"] = [this](const std::string& args){
        add_count(args); 
    };
}

void RendoCom::process_args(const std::vector<std::string>& tokens)
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
}

void RendoCom::add_count(const std::string& args)
{
    int count = Parser::str_to_int(args);
    _args["-n"] = count;
}

