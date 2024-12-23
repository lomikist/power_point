#ifndef VIEW_HPP
#define VIEW_HPP

#include "qboxlayout.h"
#include "qwidget.h"
#include <QGraphicsItem>
#include <QMainWindow>
#include <QItemEditorCreator>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>
#include <QComboBox>
#include "paint_area.hpp"

namespace gui 
{

class MyScreen : public QMainWindow
{
Q_OBJECT
public:
    MyScreen(QWidget* parent = nullptr);
    PaintArea*      get_paint_canvas() const;
    int             get_current_slide() const;
    QTextBrowser*   get_text_browser();
    void            update_elements();
private:
    int             _current_slide = 0;

    QTextBrowser*   _cmd_browser;
    QLineEdit*      _cmd_line;
    PaintArea*      _paint_canvas;

    QVBoxLayout*    _main_layout;
    QVBoxLayout*    _slide_list_layout;
    QVBoxLayout*    _pArea_layout;
    QHBoxLayout*    _scene_layout;
    QHBoxLayout*    _tools_layout;
    QGridLayout*    _tools_main_layout;
    QGridLayout*    _tools_add_item_layout; 

    QVector<QPushButton*> _slide_list_vector;
    QVector<QPushButton*> _tools_vector;

    QPushButton*    _btn_undo;
    QPushButton*    _btn_rendo;
    QPushButton*    _btn_add_item;
    QComboBox*      _box_item_type;
    
    void setup_layout();
    void setup_widgets();
    void set_connections();
    void draw_elements();
    void item_type_toggle(QPushButton* clickedButton);
};
}
#endif // VIEW_HPP
