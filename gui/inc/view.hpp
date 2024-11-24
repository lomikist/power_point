#ifndef VIEW_HPP
#define VIEW_HPP

#include "qboxlayout.h"
#include "qgraphicsview.h"
#include "qmainwindow.h"
#include "qpainter.h"
#include "qpushbutton.h"
#include "qwidget.h"
#include <QGraphicsItem>
#include <QMainWindow>
#include <QItemEditorCreator>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>
#include <iostream>
#include "paint_area.hpp"

namespace gui 
{

class MyScreen : public QMainWindow
{
Q_OBJECT
public:
    MyScreen(QWidget* parent = nullptr);
    ~MyScreen();
    PaintArea*      get_paint_canvas() const;
    int             get_current_slide() const;
    QTextBrowser*   get_text_browser();
    void            update_elements();
private:
    int _current_slide = 0;

    QTextBrowser*   _cmd_browser;
    QLineEdit*      _cmd_line;
    PaintArea*      _paintCanvas;

    QVBoxLayout*    _mainLayout;
    QVBoxLayout*    _slideListLayout;
    QVBoxLayout*    _pAreaLayout;
    QHBoxLayout*    _sceneLayout;
    QGridLayout*    _toolsLayout;

    QVector<QPushButton*> _slideListVector;
    QVector<QPushButton*> _toolsVector;

    void setup_layout();
    void set_connections();
    void draw_elements();
};
}
#endif // VIEW_HPP
