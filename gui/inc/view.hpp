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
    /*QGraphicsScene* get_scene(){return _scene;}*/
    /*QGraphicsView*  get_view(){return _view;}*/
    PaintArea*      get_paint_canvas(){return _paintCanvas;}
    void            update_elements();
private:
    /*QGraphicsView*  _view;*/
    /*QGraphicsScene* _scene;*/

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
