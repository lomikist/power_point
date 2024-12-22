#include "undo_com.hpp"
#include "editor.hpp"
#include "parser.hpp"

using namespace cli;

UndoCom::UndoCom(const CommandInfo& com) : 
         UndoSem()
{
    process_args(com._arguments);
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

