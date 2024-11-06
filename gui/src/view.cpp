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
#include "editor.hpp"
#include "qboxlayout.h"
#include "qnamespace.h"
#include "qpainter.h"
#include "qpushbutton.h"
#include "slide.hpp"
#include "view.hpp"

using namespace gui;

MyScreen::MyScreen(QWidget *parent)
    : QMainWindow(nullptr)
{
    setWindowTitle("My First Qt Window");
    setWindowState(Qt::WindowMaximized);

    _paintCanvas =  new PaintArea(this);

    setup_layout();

    _sceneLayout->addWidget(_paintCanvas);
}

MyScreen::~MyScreen()
{
};

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
    std::cout << "updatee elements";
    auto slides = core::Editor::get_instance().get_slides();
    if (!slides.empty())
    {
        for (auto&& slide : slides)
        {
            auto button = new QPushButton("hello", nullptr);
            button->setVisible(true);
            /*_slideListLayout->addWidget(button);*/
            _slideListVector.push_back(button);
        }
    }
};

