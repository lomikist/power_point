#include <QPushButton>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsTextItem>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QWidget>
#include "controller.hpp"
#include "editor.hpp"
#include "qboxlayout.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "qnamespace.h"
#include "qpushbutton.h"
#include "vizualize.hpp"
#include "view.hpp"

using namespace gui;

MyView::MyView(QWidget *parent)
    : QMainWindow(nullptr)
{
    setWindowTitle("My First Qt Window");
    resize(800, 600);
    setWindowState(Qt::WindowMaximized);
    _view = new QGraphicsView();
    _scene = new QGraphicsScene(); 
    _view->setScene(_scene);
    setup_layout();
}

MyView::~MyView()
{};

void MyView::setup_layout()
{
    QLayout *oldlayout = layout();
    if(oldlayout)
        delete oldlayout;

    _mainLayout = new QVBoxLayout;
    _toolsLayout = new QGridLayout;
    _sceneLayout = new QHBoxLayout;
    _slideListLayout = new QVBoxLayout;
    _mainLayout->addLayout(_toolsLayout);
    _mainLayout->addLayout(_sceneLayout);
    _sceneLayout->addLayout(_slideListLayout);
    setLayout(_mainLayout);
};

void MyView::update_elements()
{
    /*_toolsLayout->addWidget(new QPushButton("Button 1"), 0, 0);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 2"), 0, 1);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 3"), 0, 2);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 1"), 0, 3);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 2"), 0, 4);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 3"), 0, 5);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 4"), 1, 0);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 5"), 1, 1);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 6"), 1, 2);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 4"), 1, 3);*/
    /*_toolsLayout->addWidget(new QPushButton("Button 5"), 1, 4);*/
    _toolsLayout->addWidget(new QPushButton("Button 6"), 1, 5);

    _sceneLayout->addWidget(_view);

    /*auto& slides = core::Editor::get_instance().get_slides();*/
    /*for (auto&& slide : slides)*/
        _slideListLayout->addWidget(new QPushButton("slide N", nullptr));
    _slideListLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
};

