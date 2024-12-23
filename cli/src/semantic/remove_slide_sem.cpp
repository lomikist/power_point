#include "remove_slide_sem.hpp"
#include "parser.hpp"

using namespace cli;

RemoveSlideSem::RemoveSlideSem()
{
    _options["-i"] = [this](const std::string& opt, const std::string& args){ add_index(opt, args); };
    _options["-id"] = [this](const std::string& opt, const std::string& args){ add_id(opt, args); };
};

void RemoveSlideSem::add_id(const std::string& opt, const std::string& args)
{
    _args[opt] = args;
};

void RemoveSlideSem::add_index(const std::string& opt, const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args[opt] = index;
};

Atributes RemoveSlideSem::get_args()
{
    return _args;
}


