#ifndef SHOW_SLIDE_COM_HPP
#define SHOW_SLIDE_COM_HPP
#include <map>
#include <vector>
#include <functional>
#include "command_factory.hpp"
#include "icommand.hpp"

namespace cli 
{
class ShowSlideCom : public Acommand
{
public:
    ShowSlideCom();
    ~ShowSlideCom() = default;
    /*void process_args(const CommandInfo& com_info) override; */
    void execute() override; 
private:
    void add_index(const std::string& opt, const std::string& arg);
    void add_type(const std::string& opt, const std::string& arg);
    void add_path(const std::string& opt, const std::string& arg);
    void register_options();
    std::unordered_map<std::string, Var_SID> _args;
    
    
};
}
#endif // !SHOW_SLIDE_COM_HPP

