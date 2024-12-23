#include "remove_item_com.hpp"
#include "controller.hpp"
#include "remove_item_action.hpp"
#include <memory>

using namespace cli;

RemoveItemCom::RemoveItemCom(const CommandInfo& com) :
                _sem_analizer()
{
    _sem_analizer.process_args(com._arguments);
};

void RemoveItemCom::execute()
{
    int item_id = std::get<int>(_sem_analizer.get_args()["-id"]);
    int slide_index = std::get<int>(_sem_analizer.get_args()["-i"]);

    auto remove_action = std::make_shared<core::RemoveItemAction>(slide_index, item_id);
    core::Controller::instance()->get_editor()->process_action(remove_action);
};

