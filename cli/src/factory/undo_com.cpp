#include "undo_com.hpp"
#include "editor.hpp"
#include "parser.hpp"

using namespace cli;

UndoCom::UndoCom()
{
    _options["-n"] = [this](const std::string& opt, const std::string& args){ add_count(opt, args); };
}

void UndoCom::add_count(const std::string& opt,const std::string& args)
{
    int count = Parser::str_to_int(args);
    _args[opt] = count;
}

void UndoCom::execute()
{
    int count;
    if (_args.find("-n") != _args.end())
    {
        count = std::get<int>(_args["-n"]);
    }
    else 
        count = 1;
    while (count > 0)
    {
        core::Editor::get_instance().undo_action();
        count--;
    }
};

//TODO fix bug conntected with some parser state i think.
