#include "remove_item_sem.hpp"
#include "parser.hpp"

using namespace cli;
RemoveItemSem::RemoveItemSem(){
    _options["-id"] = [this](const std::string& opt, const std::string& args){ add_id(opt, args); };
    _options["-i"] = [this](const std::string& opt, const std::string& args){ add_index(opt, args); };
}
void RemoveItemSem::add_id(const std::string& opt, const std::string& args)
{
    int id = Parser::str_to_int(args);
    _args[opt] = id;
};

void RemoveItemSem::add_index(const std::string& opt, const std::string& args)
{
    int index = Parser::str_to_int(args);
    _args[opt] = index;
};

