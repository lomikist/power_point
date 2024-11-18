#ifndef SHOW_SLIDE_COM_HPP
#define SHOW_SLIDE_COM_HPP
#include <map>
#include <vector>
#include <functional>
#include "icommand.hpp"

namespace cli 
{
class ShowSlideCom : public ICommand
{
public:
    ShowSlideCom();
    ~ShowSlideCom() = default;
    void process_args(const std::vector<std::string>& tokens) override; 
    void execute() override; 
private:
    void add_index(const std::string& arg);
    void add_type(const std::string& arg);
    void register_options();
    std::map<std::string, std::function<void(const std::vector<std::string>&)>> _options;
    std::unordered_map<std::string, Var_SID> _args;
    
    
};
}
#endif // !SHOW_SLIDE_COM_HPP

