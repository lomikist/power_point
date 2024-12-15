#ifndef ADD_SHAPE_COM_HPP
#define ADD_SHAPE_COM_HPP
#include <map>
#include <string>
#include <vector>
#include <functional>
#include "add_slide_com.hpp"
#include "icommand.hpp"
#include "item.hpp"

namespace cli 
{

class AddItemCom : public Acommand
{
public:
    AddItemCom();
    ~AddItemCom() = default;
    void execute() override; 
private:
    void add_radius(const std::string& option, const std::string& args);
    void add_type(const std::string& option, const std::string& args);
    void add_y(const std::string& option, const std::string& args);
    void add_x(const std::string& option, const std::string& args);
    void add_w(const std::string& option, const std::string& args);
    void add_h(const std::string& option, const std::string& args);
    void add_color(const std::string& option, const std::string& args);
    void add_content(const std::string& option, const std::string& args);
    void add_index(const std::string& option, const std::string& args);
    void register_options();
    bool if_not_contain(std::vector<std::string> valid_options, model::Atributes current_options);

    Valid_types                 _valid_shape_atributes;
    std::vector<std::string>    _valid_geometry; 
    model::Atributes            _atributes;
    model::Atributes            _geometery;
};
}
#endif // !ADD_SHAPE_COM_HPP

