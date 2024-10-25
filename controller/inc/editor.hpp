#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "iobserver.hpp"
#include "isubject.hpp"
#include "model.hpp"
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <vector>
#include <variant>
#include <unordered_map>

namespace core
{
class Editor : public ISubject
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
    void notifyObservers() override;
    void addObserver(std::shared_ptr<IObserver> new_obserber) override; 
    const std::vector<std::shared_ptr<model::Slide>>& get_slides(){
        if (_model)
        {
            if (_model->get_slides().empty())
                throw std::runtime_error("slide is empty");
            else 
                return _model->get_slides();
        }
    };
};
}

#endif // !EDITOR_HPP
