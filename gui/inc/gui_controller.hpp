#ifndef GUI_CONTROLLER_HPP
#define GUI_CONTROLLER_HPP

#include "icanvas.hpp"
#include "iobserver.hpp"
#include "view.hpp"
#include <memory>
namespace gui 
{
class GuiController : public core::IObserver
{
public: 
    GuiController();
    void update() override;
private:
    std::shared_ptr<MyView> _view = nullptr;
    std::shared_ptr<core::ICanvas> _gview_canvas = nullptr;
};
}
#endif // !GUI_CONTROLLER_HPP 
