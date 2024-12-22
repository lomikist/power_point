#include "rendo_com.hpp"
#include "editor.hpp"
#include "parser.hpp"
#include "undo_sem.hpp"

using namespace cli;

RendoCom::RendoCom(const CommandInfo& com):
          RendoSem()
{
    process_args(com._arguments);
};

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

