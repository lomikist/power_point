#include "undo_com.hpp"
#include "editor.hpp"

using namespace cli;

void UndoCom::execute()
{
    core::Editor::get_instance().undo_state(); 
};

UndoCom::UndoCom()
{
}

