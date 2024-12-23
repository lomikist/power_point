#include "add_slide_com.hpp"
#include "add_slide_action.hpp"
#include "controller.hpp"
#include <memory>
#include <string>

using namespace cli;

AddSlideCom::AddSlideCom(const CommandInfo& com) :
            _sem_analizer()
{
    _sem_analizer.process_args(com._arguments);
};

void AddSlideCom::execute()
{
    int index;
    std::string name = std::get<std::string>(_sem_analizer.get_args()["-n"]);

    if (_sem_analizer.get_args().find("-i") != _sem_analizer.get_args().end())
        index = std::get<int>(_sem_analizer.get_args()["-i"]);
    else 
        index = -1;

    auto add_action = std::make_shared<core::AddSlideAction>(std::make_shared<model::Slide>(name), index);
    core::Controller::instance()->get_editor()->process_action(add_action);
};

