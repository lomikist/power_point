#include "add_slide_com.hpp"
#include "add_slide_action.hpp"
#include "editor.hpp"
#include "parser.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace cli;

AddSlideCom::AddSlideCom(const CommandInfo& com) :
             AddSlideSem()
{
    process_args(com._arguments);
};

void AddSlideCom::execute()
{
    int index;
    std::string name = std::get<std::string>(_args["-n"]);

    if (_args.find("-i") != _args.end())
        index = std::get<int>(_args["-i"]);
    else 
        index = -1;

    auto add_action = std::make_shared<core::AddSlideAction>(std::make_shared<model::Slide>(name), index);
    core::Editor& editot = core::Editor::get_instance();
    editot.process_action(add_action);
};

