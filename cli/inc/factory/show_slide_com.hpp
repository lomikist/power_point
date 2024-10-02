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
    void execute(const std::vector<std::string>& tokens) override; 
private:
    void add_index(const std::vector<std::string>& args);
    void register_options();
    std::map<std::string, std::function<void(const std::vector<std::string>&)>> _options;
};
}
#endif // !SHOW_SLIDE_COM_HPP

