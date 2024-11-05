#include "gui_controller.hpp"
#include "icanvas.hpp"
#include "qapplication.h"
#include "qt_wrapper.hpp"
#include "vizualize.hpp"

using namespace gui;

GuiController::GuiController()
{
    _screen = std::make_shared<gui::MyScreen>();
    _screen->update_elements();
    _screen->show();
    
    _pview_canvas = std::make_shared<core::QtWrapper>(_screen->get_painter());

};

void GuiController::update()
{
    core::Vizualizer::get_instance().process_slide(_pview_canvas, 0);
    _screen->update_elements(); 
    _screen->show();
};
