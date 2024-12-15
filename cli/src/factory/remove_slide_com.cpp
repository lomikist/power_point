#include "remove_slide_com.hpp"
#include "parser.hpp"
#include "editor.hpp"
#include "remove_slide_action.hpp"
#include <memory>
#include <stdexcept>

using namespace cli;

RemoveSlideCom::RemoveSlideCom()
{
    _options["-i"] = [this](const std::string& opt, const std::string& args){ add_index(opt, args); };
    _options["-id"] = [this](const std::string& opt, const std::string& args){ add_id(opt, args); };
};

void RemoveSlideCom::execute()
{
    /*std::cout << "exec removslide" << std::endl;*/
    int id = std::get<int>(_args["-i"]);

    auto remove_act = std::make_shared<core::RemoveSlideAction>(id);
    core::Editor::get_instance().process_action(remove_act);
};

void RemoveSlideCom::add_id(const std::string& opt, const std::string& args)
{
    _args[opt] = args;
};

void RemoveSlideCom::add_index(const std::string& opt, const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args[opt] = index;
};

