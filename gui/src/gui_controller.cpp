#include "gui_controller.hpp"
#include "icanvas.hpp"
#include "qt_wrapper.hpp"
#include "vizualize.hpp"

using namespace gui;

GuiController::GuiController()
{
    _view = std::make_shared<gui::MyView>();
    _view->show();
    _view->update_elements();
    _gview_canvas = std::make_shared<core::QtWrapper>(_view->get_view()); 

};

void GuiController::update()
{
    core::Vizualizer::get_instance().process_slide(_gview_canvas, 0);
    _view->update_elements(); 
};
