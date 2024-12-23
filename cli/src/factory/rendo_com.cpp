#include "rendo_com.hpp"
#include "controller.hpp"

using namespace cli;

RendoCom::RendoCom(const CommandInfo& com):
          _sem_analizer()
{
    _sem_analizer.process_args(com._arguments);
};

void RendoCom::execute()
{
    int count;
    if (_sem_analizer.get_args().find("-n") != _sem_analizer.get_args().end())
        count = std::get<int>(_sem_analizer.get_args()["-n"]);
    else 
        count = 1;
    while (count > 0)
    {
        core::Controller::instance()->get_editor()->rendo_action();
        count--;
    }
};

