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
    QGraphicsScene* get_scene(){return _scene;}
    QGraphicsView*  get_view(){return _view;}
    PaintArea*      get_paint_canvas(){return _paintCanvas;}
    void            update_elements();
private:
    QGraphicsView*  _view;
    QGraphicsScene* _scene;

    PaintArea*      _paintCanvas;

    QVBoxLayout*    _mainLayout;
    QVBoxLayout*    _slideListLayout;
    QGridLayout*    _toolsLayout;
    QHBoxLayout*    _sceneLayout;
    QVector<QPushButton*> _slideListVector;
    QVector<QPushButton*> _toolsVector;
protected:
    void setup_layout();
};
}
#endif // VIEW_HPP
