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
    std::shared_ptr<MyScreen> _screen = nullptr;
    std::shared_ptr<core::ICanvas> _gview_canvas = nullptr;
    std::shared_ptr<core::ICanvas> _pview_canvas = nullptr;
};
}
#endif // !GUI_CONTROLLER_HPP 
