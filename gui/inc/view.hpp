#ifndef VIEW_HPP
#define VIEW_HPP

#include "qboxlayout.h"
#include "qgraphicsview.h"
#include "qmainwindow.h"
#include "qpushbutton.h"
#include <QGraphicsItem>
#include <QMainWindow>
#include <QItemEditorCreator>
#include <QPushButton>
#include <cstddef>
#include <memory>
#include <tuple>
namespace gui 
{
class MyView : public QMainWindow
{
Q_OBJECT
public:
    MyView(QWidget* parent = nullptr);
    ~MyView();
    QGraphicsScene* get_scene(){return _scene;}
    QGraphicsView* get_view(){return _view;}
    void update_elements();
private:
    QGraphicsView*  _view;
    QGraphicsScene* _scene;
    QVBoxLayout*    _mainLayout;
    QVBoxLayout*    _slideListLayout;
    QGridLayout*    _toolsLayout;
    QHBoxLayout*    _sceneLayout;
    QVector<QPushButton*> _slideListVector;
    QVector<QPushButton*> _toolsVector;
protected:
    void setup_layout();
    /*void paintEvent(QPaintEvent* event) override;*/
};
}
#endif // VIEW_HPP
