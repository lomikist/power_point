#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "iaction.hpp"
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
    Editor(){};
    void set_model(std::shared_ptr<model::Model> model); 
    void notifyObservers() override;
    void addObserver(std::shared_ptr<IObserver> new_obserber) override; 
    
    void process_action(std::shared_ptr<Iaction> action);
    void undo_action();
    void rendo_action();
private:
    std::shared_ptr<model::Model> _model;
    std::stack<std::shared_ptr<Iaction>> _undo_stack;
    std::stack<std::shared_ptr<Iaction>> _rendo_stack;
};
}

#endif // !EDITOR_HPP


