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
#include <sstream>
#include "add_item_com.hpp"
#include "add_item_win.hpp"
#include "controller.hpp"
#include "editor.hpp"
#include "logger.hpp"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qnamespace.h"
#include "gui_wrapper.hpp"
#include "qpushbutton.h"
#include "view.hpp"

using namespace gui;

MyScreen::MyScreen(QWidget *parent)
    : QMainWindow(nullptr)
{
    setWindowTitle("павер поинт");
    setWindowState(Qt::WindowMaximized);
    setup_layout();
    setup_widgets();
    set_connections();
}

PaintArea* MyScreen::get_paint_canvas() const
{
    return _paint_canvas;
}

int MyScreen::get_current_slide() const
{
    return _current_slide;
}

void MyScreen::setup_widgets()
{
    _paint_canvas =  new PaintArea(this);
    _cmd_line =     new QLineEdit(this);
    _cmd_browser =  new QTextBrowser(this);
    _cmd_browser->setFixedHeight(100);

    _pArea_layout->addWidget(_paint_canvas);
    _pArea_layout->addWidget(_cmd_line);
    _pArea_layout->addWidget(_cmd_browser);

    //// Toolbar ////
    _btn_undo =         new QPushButton("Undo", this);
    _btn_rendo =        new QPushButton("Rendo", this);
    _btn_add_item =     new QPushButton("Add Item", this);
    _box_item_type =    new QComboBox(this);
    
    _btn_add_rect->setCheckable(true);
    _btn_add_elipse->setCheckable(true);
    _btn_add_textbox->setCheckable(true);

    QLabel* item_type = new QLabel("Item type: ", this);
    for (auto&& item : cli::AddItemCom::s_valid_shape_atributes)
        _box_item_type->addItem(QString::fromStdString(item.first));

    _tools_add_item_layout->addWidget(_btn_add_item, 0, 0, 1, 2);
    _tools_add_item_layout->addWidget(_box_item_type, 1, 1);
    _tools_add_item_layout->addWidget(item_type, 1, 0);

    _tools_main_layout->addWidget(_btn_add_rect, 1, 0);
    _tools_main_layout->addWidget(_btn_add_elipse, 1, 1);
    _tools_main_layout->addWidget(_btn_add_textbox, 1, 4); 
    _tools_main_layout->addWidget(_btn_undo, 0, 0);
    _tools_main_layout->addWidget(_btn_rendo, 0, 1);
};

void MyScreen::setup_layout()
{
    QLayout *oldlayout = layout();
    if(oldlayout)
        delete oldlayout;

    _main_layout =              new QVBoxLayout;
    _tools_layout =             new QHBoxLayout;
    _scene_layout =             new QHBoxLayout;
    _slide_list_layout =        new QVBoxLayout;
    _pArea_layout =             new QVBoxLayout;
    _tools_add_item_layout =    new QGridLayout;
    _tools_main_layout =        new QGridLayout;

    _tools_layout->addLayout(_tools_main_layout);
    _tools_layout->addLayout(_tools_add_item_layout);
    _main_layout->addLayout(_tools_layout);
    _main_layout->addLayout(_scene_layout);
    _scene_layout->addLayout(_slide_list_layout);
    _scene_layout->addLayout(_pArea_layout);

    setLayout(_main_layout);
};


void MyScreen::set_connections()
{
    QObject::connect(_cmd_line, &QLineEdit::returnPressed, [&]()
    {
        std::stringstream stream(_cmd_line->text().toStdString());
        try {
            auto cmd = core::Controller::get_instance().get_parser().parse(stream);
            if (cmd) {
                cmd->execute();
            }
            _paint_canvas->getImage()->fill(Qt::white);

            auto pview_canvas = std::make_shared<core::GuiPainterWrapper>(_paint_canvas->getPainter());
            core::Vizualizer::get_instance().process_slide(pview_canvas, _current_slide);

            _paint_canvas->repaint();
            update_elements();
        }catch (const std::exception& e)
        {
            core::Logger::get_instance().notify_loggers(e.what());
        }
    });
    QObject::connect(_btn_undo, &QPushButton::clicked, [&]()
    {
        core::Editor::get_instance().undo_action(); 
    });
    QObject::connect(_btn_rendo, &QPushButton::clicked, [&]()
    {
        core::Editor::get_instance().rendo_action(); 
    });

    QObject::connect(_btn_add_item, &QPushButton::clicked, [&]()
    {
        auto type = _box_item_type->currentText();
        AddItemWin* add_popup = new AddItemWin(type.toStdString(), _current_slide, this); 
        add_popup->show();
    });

    QObject::connect(_btn_add_elipse, &QPushButton::clicked, [&]()
    {
        
    });
    QObject::connect(_btn_add_textbox, &QPushButton::clicked, [&]()
    {
        
    });
    QObject::connect(_btn_add_rect, &QPushButton::clicked, [&]()
    {

    });
}

void MyScreen::update_elements()
{
    auto slides = core::Controller::get_instance().get_model()->get_slides();

    if (!slides.empty())
    {
        for (auto&& slide : slides)
        {
            auto button_it = std::find_if(_slide_list_vector.begin(), _slide_list_vector.end(), [&](QPushButton* elem){
                return elem->property("id") == QString::number(slide->get_id()); 
            });
            if (button_it == _slide_list_vector.end())
            {
                auto button = new QPushButton(
                    QString::fromStdString(slide->get_title() + " " + std::to_string(slide->get_id())),
                    nullptr
                );

                QObject::connect(button, &QPushButton::clicked, [slide, this]()
                {
                    _current_slide = slide->get_id();
                    _paint_canvas->getImage()->fill(Qt::white);

                    auto pview_canvas = std::make_shared<core::GuiPainterWrapper>(_paint_canvas->getPainter());
                    core::Vizualizer::get_instance().process_slide(pview_canvas, _current_slide);

                    _paint_canvas->repaint();
                });

                button->setProperty("title", QString::fromStdString(slide->get_title()));
                button->setProperty("id", QString::number(slide->get_id()));

                _slide_list_layout->addWidget(button);
                _slide_list_vector.push_back(button);
            }
        }
    }
    draw_elements();
};

void MyScreen::draw_elements()
{
    for (auto&& btn : _slide_list_vector)
    {
        btn->setStyleSheet("background-color: gray;");
        QPixmap pixmap(PAREA_WIDTH, PAREA_HEIGHT);

        pixmap.fill(Qt::white); 
        pixmap.scaled(QSize(BTN_ICONE_WIDTH, BTN_ICONE_HEIGHT));

        QPainter slide_list_painter(&pixmap);
        slide_list_painter.setPen(QPen(Qt::black,3));
        slide_list_painter.setBrush(QBrush(Qt::red));

        auto _btn_canvas = std::make_shared<core::GuiPainterWrapper>(&slide_list_painter);
        core::Vizualizer::get_instance().process_slide(_btn_canvas, btn->property("id").toInt());

        btn->setVisible(true); 
        btn->setIcon(QIcon(pixmap));
        btn->setIconSize(QSize(BTN_ICONE_WIDTH, BTN_ICONE_HEIGHT));
    }
}

QTextBrowser* MyScreen::get_text_browser()
{
    return _cmd_browser;
}

