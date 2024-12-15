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
    _options["-n"] = [this](const std::string& opt,const std::string& args){
        add_count(opt, args); 
    };
}

void RendoCom::add_count(const std::string& opt, const std::string& args)
{
    int count = Parser::str_to_int(args);
    _args[opt] = count;
}

