#include "remove_slide_com.hpp"
#include "controller.hpp"
#include "parser.hpp"
#include "editor.hpp"
#include "remove_slide_action.hpp"
#include <memory>
#include <stdexcept>

using namespace cli;

RemoveSlideCom::RemoveSlideCom(const CommandInfo& com)
{
    process_args(com._arguments);
};

void RemoveSlideCom::execute()
{
    int id = std::get<int>(_args["-i"]);

    auto remove_act = std::make_shared<core::RemoveSlideAction>(id);
    core::Controller::instance()->get_editor()->process_action(remove_act);
};

