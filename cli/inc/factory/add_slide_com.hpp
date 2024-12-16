#ifndef ADD_SLIDE_COM_HPP
#define ADD_SLIDE_COM_HPP

#include <map>
#include <vector>
#include <functional>
#include "command_factory.hpp"
#include "icommand.hpp"

namespace cli 
{

class AddSlideCom : public Acommand
{
public:
    AddSlideCom();
    ~AddSlideCom() = default;
    /*void process_args(const CommandInfo& com_info) override; */
    void execute() override; 
private:
    void add_title(const std::string& opt, const std::string& args);
    void add_index(const std::string& opt, const std::string& args);
    std::unordered_map<std::string, Var_SID> _args;

};
}
#endif // !ADD_SLIDE_COM_HPP

