#include "rendo_com.hpp"
#include "controller.hpp"

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
        core::Controller::get_instance().get_editor()->rendo_action();
        count--;
    }
};

