#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "model.hpp"
#include <cstddef>
#include <memory>
#include <vector>
#include <variant>
#include <unordered_map>

namespace core
{
class Editor 
{
private:
    Editor();
    Editor(const Editor&);
    std::shared_ptr<model::Model> _model;
public: 
    ~Editor();
    static Editor& get_instance();
    void set_model(std::shared_ptr<model::Model> model); 

    void add_slide(int index, const std::string& name);
    void add_shape(const std::unordered_map<std::string, std::variant<std::string, int, double>>& );  
    void remove_shape(int slide_index, int shape_index);
    void remove_slide(int index);
};
}

#endif // !EDITOR_HPP
