#ifndef ADD_ITEM_SEM_HPP
#define ADD_ITEM_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class AddItemSem : public ASemAn
{
public:
    static bool if_not_contain(std::vector<std::string> valid_options, model::Atributes current_options);

protected:
    AddItemSem();

    model::Atributes    _atributes;
    model::Atributes    _geometery;
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
};
}
#endif // ADD_ITEM_SEM_HPP  
