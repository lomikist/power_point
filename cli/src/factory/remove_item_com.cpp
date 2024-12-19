#include "remove_item_com.hpp"
#include "parser.hpp"
#include "editor.hpp"
#include "remove_item_action.hpp"
#include <memory>
#include <stdexcept>

using namespace cli;

RemoveItemCom::RemoveItemCom(const CommandInfo& com) :
                RemoveItemSem()
{
    process_args(com._arguments);
};

void RemoveItemCom::execute()
{
    int item_id = std::get<int>(_args["-id"]);
    int slide_index = std::get<int>(_args["-i"]);

    auto remove_action = std::make_shared<core::RemoveItemAction>(slide_index, item_id);
    core::Editor::get_instance().process_action(remove_action);
};

