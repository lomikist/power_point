#ifndef REMOVE_SLIDE_COM_HPP
#define REMOVE_SLIDE_COM_HPP

#include <map>
#include <vector>
#include <functional>
#include "icommand.hpp"

namespace cli 
{

class RemoveSlideCom : public ICommand
{
public:
    RemoveSlideCom();
    ~RemoveSlideCom() = default;
    void process_args(const std::vector<std::string>& tokens) override; 
    void execute() override; 
private:
    void add_id(const std::string& args);
    void add_index(const std::string& args);
    std::map<std::string, F_vs> _options;
    std::unordered_map<std::string, Var_SID> _args;

};
}
#endif // !REMOVE_SLIDE_COM_HPP

