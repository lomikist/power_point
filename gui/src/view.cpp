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
#include <algorithm>
#include <sstream>
#include "controller.hpp"
#include "editor.hpp"
#include "qboxlayout.h"
#include "qlineedit.h"
#include "qnamespace.h"
#include "qpainter.h"
#include "qpen.h"
#include "qpixmap.h"
#include "qpushbutton.h"
#include "qt_wrapper.hpp"
#include "slide.hpp"
#include "vizualize.hpp"
#include "view.hpp"

using namespace gui;

MyScreen::MyScreen(QWidget *parent)
    : QMainWindow(nullptr)
{
    setWindowTitle("My First Qt Window");
    setWindowState(Qt::WindowMaximized);

    setup_layout();

    _paintCanvas =  new PaintArea(this);
    _cmd_line = new QLineEdit;
    _cmd_browser = new QTextBrowser;
    _cmd_browser->setFixedHeight(100);

    _pAreaLayout->addWidget(_paintCanvas);
    _pAreaLayout->addWidget(_cmd_line);
    _pAreaLayout->addWidget(_cmd_browser);
    set_connections();
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
    _pAreaLayout = new QVBoxLayout;
    _mainLayout->addLayout(_toolsLayout);
    _mainLayout->addLayout(_sceneLayout);
    _sceneLayout->addLayout(_slideListLayout);
    _sceneLayout->addLayout(_pAreaLayout);
    setLayout(_mainLayout);
};


void MyScreen::set_connections()
{
    QObject::connect(_cmd_line, &QLineEdit::returnPressed, [&]()
    {
        std::stringstream stream(_cmd_line->text().toStdString());
        try {
            auto cmd = core::Controller::get_instance().get_parser().parse(stream);
            if (cmd)
            {
                cmd->execute();
            }
            _paintCanvas->repaint();
            update_elements();
        }catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
   });
}

void MyScreen::update_elements()
{
    auto slides = core::Editor::get_instance().get_slides();
    if (!slides.empty())
    {
        for (auto&& slide : slides)
        {
            auto button_it = std::find_if(_slideListVector.begin(), _slideListVector.end(), [&](QPushButton* elem){
                return elem->property("id") == QString::number(slide->get_id()); 
            });
            if (button_it == _slideListVector.end())
            {
                auto button = new QPushButton(QString::fromStdString(slide->get_title() + " " + std::to_string(slide->get_id())), nullptr);

                QObject::connect(button, &QPushButton::clicked, [slide, this]()
                {
                    _paintCanvas->getImage()->fill(Qt::white);

                    auto _pview_canvas = std::make_shared<core::QtWrapper>(_paintCanvas->getPainter());
                    core::Vizualizer::get_instance().process_slide(_pview_canvas, slide->get_id());

                    _paintCanvas->repaint();
                });

                button->setProperty("title", QString::fromStdString(slide->get_title()));
                button->setProperty("id", QString::number(slide->get_id()));

                _slideListLayout->addWidget(button);
                _slideListVector.push_back(button);
            }
        }
    }
    draw_elements();
};

void MyScreen::draw_elements()
{
    for (auto&& btn : _slideListVector)
    {
        btn->setStyleSheet("background-color: gray;");
        QPixmap pixmap(1000, 800);
        pixmap.fill(Qt::white); 
        pixmap.scaled(QSize(100,100));

        QPainter slide_list_painter(&pixmap);
        slide_list_painter.setPen(QPen(Qt::black,3));
        slide_list_painter.setBrush(QBrush(Qt::red));

        auto _btn_canvas = std::make_shared<core::QtWrapper>(&slide_list_painter);
        core::Vizualizer::get_instance().process_slide(_btn_canvas, btn->property("id").toInt());

        btn->setVisible(true); 
        btn->setIconSize(QSize(100,100));
        btn->setIcon(QIcon(pixmap));
    }
}
