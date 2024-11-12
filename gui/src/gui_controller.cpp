#include "gui_controller.hpp"
#include "icanvas.hpp"
#include "qapplication.h"
#include "qt_wrapper.hpp"
#include "vizualize.hpp"

using namespace gui;

GuiController::GuiController()
{
    _screen = std::make_shared<gui::MyScreen>();
    _screen->show();

    _pview_canvas = std::make_shared<core::QtWrapper>(_screen->get_paint_canvas()->getPainter());
};

void GuiController::update()
{
    _screen->update_elements(); 
    _screen->update();
    _screen->show();
    core::Vizualizer::get_instance().process_slide(_pview_canvas, _screen->get_current_slide());
};

std::shared_ptr<MyScreen> GuiController::get_screen() const 
{
    return _screen;
}
