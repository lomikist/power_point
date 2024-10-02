#ifndef ADD_SLIDE_COM_HPP
#define ADD_SLIDE_COM_HPP
#include <map>
#include <vector>
#include <functional>
#include "icommand.hpp"

namespace cli 
{
class AddSlideCom : public ICommand
{
public:
    AddSlideCom();
    ~AddSlideCom() = default;
    void execute(const std::vector<std::string>& tokens) override; 
private:
    void add_title(const std::vector<std::string>& args);
    void add_index(const std::vector<std::string>& args);
    void register_options();
    std::map<std::string, std::function<void(const std::vector<std::string>&)>> _options;
};
}
#endif // !ADD_SLIDE_COM_HPP

