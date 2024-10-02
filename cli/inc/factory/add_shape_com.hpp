#ifndef ADD_SHAPE_COM_HPP
#define ADD_SHAPE_COM_HPP
#include <map>
#include <string>
#include <vector>
#include <functional>
#include "icommand.hpp"

namespace cli 
{
class AddShapeCom : public ICommand
{
public:
    AddShapeCom();
    ~AddShapeCom() = default;
    void execute(const std::vector<std::string>& tokens) override; 
private:
    void add_type(const std::vector<std::string>& args);
    void add_y(const std::vector<std::string>& args);
    void add_x(const std::vector<std::string>& args);
    void add_w(const std::vector<std::string>& args);
    void add_h(const std::vector<std::string>& args);
    void add_color(const std::vector<std::string>& args);
    void add_index(const std::vector<std::string>& args);
    void register_options();
    std::map<std::string, std::function<void(const std::vector<std::string>&)>> _options;
};
}
#endif // !ADD_SHAPE_COM_HPP

