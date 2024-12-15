#ifndef REMOVE_SLIDE_COM_HPP
#define REMOVE_SLIDE_COM_HPP

#include <map>
#include <vector>
#include <functional>
#include "command_factory.hpp"
#include "icommand.hpp"

namespace cli 
{

class RemoveSlideCom : public Acommand
{
public:
    RemoveSlideCom();
    ~RemoveSlideCom() = default;
    /*void process_args(const CommandInfo& com_info) override; */
    void execute() override; 
private:
    void add_id(const std::string& opt, const std::string& args);
    void add_index(const std::string& opt, const std::string& args);
    std::unordered_map<std::string, Var_SID> _args;

};
}
#endif // !REMOVE_SLIDE_COM_HPP

