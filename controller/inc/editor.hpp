#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "icommand.hpp"
#include "iobserver.hpp"
#include "isubject.hpp"
#include "item.hpp"
#include "model.hpp"
#include "slide.hpp"
#include <cstddef>
#include <memory>
#include <stack>

namespace core
{
class Editor : public ISubject
{
public: 
    ~Editor(){};
    static Editor& get_instance();
    void set_model(std::shared_ptr<model::Model> model); 
    void add_slide(int index, const std::string& name);
    void add_item(const  model::Atributes& geometery, const  model::Atributes& atributes);
    void remove_item(int slide_index, int shape_index);
    void remove_slide(int index);
    void notifyObservers() override;
    void addObserver(std::shared_ptr<IObserver> new_obserber) override; 

    void save_state();
    void undo_state();
    void rendo_state();
private:
    Editor(){};
    std::shared_ptr<model::Model> _model;
    std::stack<model::ModelMemento> _undo_stack;
    std::stack<model::ModelMemento> _rendo_stack;
};
}

#endif // !EDITOR_HPP
