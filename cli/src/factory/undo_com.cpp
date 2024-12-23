#include "undo_com.hpp"
#include "controller.hpp"

using namespace cli;

UndoCom::UndoCom(const CommandInfo& com) : 
         _sem_analizer()
{
    _sem_analizer.process_args(com._arguments);
}

void UndoCom::execute()
{
    int count;
    if (_sem_analizer.get_args().find("-n") != _sem_analizer.get_args().end())
    {
        count = std::get<int>(_sem_analizer.get_args()["-n"]);
    }
    else 
        count = 1;
    while (count > 0)
    {
        core::Controller::instance()->get_editor()->undo_action();
        count--;
    }
};

