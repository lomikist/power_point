#include "add_slide_sem.hpp"
#include "parser.hpp"

using namespace cli;

AddSlideSem::AddSlideSem()
{
    _options["-n"] = [this](const std::string& opt, const std::string& args){ add_title(opt, args); };
    _options["-i"] = [this](const std::string& opt, const std::string& args){ add_index(opt, args); };
};

Atributes AddSlideSem::get_args()
{
    return _args;
}

void AddSlideSem::add_title(const std::string& opt, const std::string& args)
{
    _args[opt] = args;
};

void AddSlideSem::add_index(const std::string& opt, const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args[opt] = index;
};
