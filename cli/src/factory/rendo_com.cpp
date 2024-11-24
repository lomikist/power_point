#include "rendo_com.hpp"
#include "editor.hpp"

using namespace cli;

void RendoCom::execute()
{
    core::Editor::get_instance().rendo_state();
};

RendoCom::RendoCom()
{}

