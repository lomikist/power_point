#include "undo_sem.hpp"
#include "parser.hpp"

using namespace cli;

UndoSem::UndoSem()
{
    _options["-n"] = [this](const std::string& opt, const std::string& args){ add_count(opt, args); };
};

void UndoSem::add_count(const std::string& opt,const std::string& args)
{
    int count = Parser::str_to_int(args);
    _args[opt] = count;
}

