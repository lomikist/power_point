#ifndef ICOMMAND_VISITOR_HPP
#define ICOMMAND_VISITOR_HPP

#include "add_slide_com.hpp"
#include "show_slide_com.hpp"
#include "add_shape_com.hpp"
#include <memory>
namespace core
{
class ICommandVisitor {
public:
    virtual void visit_cmd(const std::shared_ptr<cli::AddSlideCom>& cmd) = 0;
    virtual void visit_cmd(const std::shared_ptr<cli::ShowSlideCom>& cmd) = 0;
    virtual void visit_cmd(const std::shared_ptr<cli::AddShapeCom>& cmd) = 0;
};
}
#endif // !ICOMMAND_VISITOR_HPP
