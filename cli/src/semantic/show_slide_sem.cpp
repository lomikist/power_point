#include "parser.hpp"
#include "show_slid_sem.hpp"

using namespace cli;

ShowSlideSem::ShowSlideSem()
{
    _options["-i"] = [this](const std::string& opt,const std::string& args){ add_index(opt, args); };
    _options["-t"] = [this](const std::string& opt,const std::string& args){ add_type(opt, args); };
    _options["-p"] = [this](const std::string& opt,const std::string& args){ add_path(opt, args); };
};

void ShowSlideSem::add_index(const std::string& opt,const std::string& arg)
{
    int index = Parser::str_to_int(arg); 
    _args[opt] = index;
}

void ShowSlideSem::add_type(const std::string& opt,const std::string& arg)
{
    _args[opt] = arg;
}

void ShowSlideSem::add_path(const std::string& opt,const std::string& arg)
{
    _args[opt] = arg;
}

Atributes ShowSlideSem::get_args()
{
    return _args;
}


