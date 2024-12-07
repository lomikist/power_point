#ifndef IACTION_HPP
#define IACTION_HPP

#include "model.hpp"
#include <memory>
namespace core 
{
class Iaction : public std::enable_shared_from_this<Iaction> 
{
public:
    virtual ~Iaction(){};
    virtual std::shared_ptr<Iaction> do_action(std::shared_ptr<model::Model> model) = 0; 
};
}
#endif // !IACTION_HPP
