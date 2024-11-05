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
#include "qnamespace.h"
#include "qpainter.h"
#include "qpushbutton.h"
#include "view.hpp"

using namespace gui;

MyScreen::MyScreen(QWidget *parent)
    : QMainWindow(nullptr)
{
    setWindowTitle("My First Qt Window");
    resize(800, 600);
    setWindowState(Qt::WindowMaximized);

    _paintCanvas =  new PaintArea(this, _painter);

    setup_layout();
}

MyScreen::~MyScreen()
{};

void MyScreen::setup_layout()
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

void MyScreen::update_elements()
{
    _toolsLayout->addWidget(new QPushButton("Button 6"), 1, 5);

    _sceneLayout->addWidget(_paintCanvas);

    _slideListLayout->addWidget(new QPushButton("slide N", nullptr));
    _slideListLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
};

