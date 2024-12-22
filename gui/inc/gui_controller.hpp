#ifndef GUI_CONTROLLER_HPP
#define GUI_CONTROLLER_HPP

#include "icanvas.hpp"
#include "iobserver.hpp"
#include "view.hpp"
#include <memory>
namespace gui 
{

const int PAREA_HEIGHT = 700;
const int PAREA_WIDTH = 1300;
const int BTN_ICONE_HEIGHT = 100;
const int BTN_ICONE_WIDTH = 100;

class GuiController : public core::IObserver
{
public: 
    GuiController();
    void update() override;
    std::shared_ptr<MyScreen> get_screen() const;
    void save_img(const std::string& path);
private:
    std::shared_ptr<MyScreen> _screen = nullptr;
    std::shared_ptr<core::ICanvas> _pview_canvas = nullptr;
};
}
#endif // !GUI_CONTROLLER_HPP 
