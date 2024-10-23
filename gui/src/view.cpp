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
#include "qboxlayout.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "qnamespace.h"
#include "qpushbutton.h"
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
    _buttonsLayout = new QGridLayout;
    _sceneLayout = new QHBoxLayout;
    _slideListLayout = new QVBoxLayout;

    _mainLayout->addLayout(_buttonsLayout);
    _mainLayout->addLayout(_sceneLayout);
    _sceneLayout->addLayout(_slideListLayout);

    _buttonsLayout->addWidget(new QPushButton("Button 1"), 0, 0);
    _buttonsLayout->addWidget(new QPushButton("Button 2"), 0, 1);
    _buttonsLayout->addWidget(new QPushButton("Button 3"), 0, 2);
    _buttonsLayout->addWidget(new QPushButton("Button 1"), 0, 3);
    _buttonsLayout->addWidget(new QPushButton("Button 2"), 0, 4);
    _buttonsLayout->addWidget(new QPushButton("Button 3"), 0, 5);
    _buttonsLayout->addWidget(new QPushButton("Button 4"), 1, 0);
    _buttonsLayout->addWidget(new QPushButton("Button 5"), 1, 1);
    _buttonsLayout->addWidget(new QPushButton("Button 6"), 1, 2);
    _buttonsLayout->addWidget(new QPushButton("Button 4"), 1, 3);
    _buttonsLayout->addWidget(new QPushButton("Button 5"), 1, 4);
    _buttonsLayout->addWidget(new QPushButton("Button 6"), 1, 5);

    _sceneLayout->addWidget(_view);
    _slideListLayout->addWidget(new QPushButton("fs"));
    _slideListLayout->addWidget(new QPushButton("fs"));
    _slideListLayout->addWidget(new QPushButton("fs"));
    _slideListLayout->addWidget(new QPushButton("fs"));
    _slideListLayout->addWidget(new QPushButton("fs"));
    _slideListLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));

    setLayout(_mainLayout);
};

