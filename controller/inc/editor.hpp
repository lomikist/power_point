#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "iobserver.hpp"
#include "isubject.hpp"
#include "model.hpp"
#include "slide.hpp"
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
    std::shared_ptr<model::Model> _model;
public: 
    ~Editor();
    static Editor& get_instance();
    void set_model(std::shared_ptr<model::Model> model); 
    void add_slide(int index, const std::string& name);
    void add_shape(const std::unordered_map<std::string, std::variant<std::string, int, double>>& );  
    void remove_shape(int slide_index, int shape_index);
    void remove_slide(int index);
    //////////////////////
    ///its not should be here 
    const std::vector<std::shared_ptr<model::Slide>>& get_slides() const;

    ////////////////////
    void notifyObservers() override;
    void addObserver(std::shared_ptr<IObserver> new_obserber) override; 
};
}

#endif // !EDITOR_HPP
