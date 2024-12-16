#include "add_slide_com.hpp"
#include "add_slide_action.hpp"
#include "editor.hpp"
#include "parser.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace cli;

AddSlideCom::AddSlideCom()
{
    _options["-n"] = [this](const std::string& opt, const std::string& args){ add_title(opt, args); };
    _options["-i"] = [this](const std::string& opt, const std::string& args){ add_index(opt, args); };
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

void AddSlideCom::add_title(const std::string& opt, const std::string& args)
{
    _args[opt] = args;
};

void AddSlideCom::add_index(const std::string& opt, const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args[opt] = index;
};
