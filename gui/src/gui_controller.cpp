#include "gui_controller.hpp"
#include "gui_wrapper.hpp"
#include "qobject.h"
#include "vizualize.hpp"

using namespace gui;

GuiController::GuiController()
{
    _screen = std::make_shared<MyScreen>();
    _screen->show();

    _pview_canvas = std::make_shared<core::GuiPainterWrapper>(_screen->get_paint_canvas()->get_painter());
};

void GuiController::update()
{
    core::Vizualizer::get_instance().process_slide(_pview_canvas, _screen->get_current_slide());
    _screen->update_elements(); 
    _screen->update();
    _screen->show();
};

std::shared_ptr<MyScreen> GuiController::get_screen() const 
{
    return _screen;
}

void GuiController::save_img(const std::string& path)
{
    if (_screen->get_paint_canvas()->get_image()->save(QString::fromStdString(path)))
    {}
    else 
    {}
}

