#ifndef ADD_SHAPE_COM_HPP
#define ADD_SHAPE_COM_HPP
#include <map>
#include <string>
#include <vector>
#include <functional>
#include "add_slide_com.hpp"
#include "icommand.hpp"

namespace cli 
{

class AddItemCom : public ICommand
{
public:
    AddItemCom();
    ~AddItemCom() = default;
    void process_args(const std::vector<std::string>& tokens) override; 
    void execute() override; 
private:
    void add_radius(const std::string& args);
    void add_type(const std::string& args);
    void add_y(const std::string& args);
    void add_x(const std::string& args);
    void add_w(const std::string& args);
    void add_h(const std::string& args);
    void add_color(const std::string& args);
    void add_content(const std::string& args);
    void add_index(const std::string& args);
    void register_options();

    Valid_types _valid_shape_atributes;
    std::map<std::string, F_vs> _optional_funcs;
    std::vector<std::string> _valid_geometry; 
    std::unordered_map<std::string, Var_SID> _atributes;
    std::unordered_map<std::string, Var_SID> _geometery;
};
}
#endif // !ADD_SHAPE_COM_HPP

