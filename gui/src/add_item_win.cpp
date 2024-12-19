#include "add_item_win.hpp"
#include "add_item_action.hpp"
#include "add_item_com.hpp"
#include "editor.hpp"
#include "item.hpp"
#include "qboxlayout.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "type.hpp"
#include <QLabel>
using namespace gui;

AddItemWin::AddItemWin(const std::string& type, int slide_index, QWidget* parent) :
                        QMainWindow(parent),
                        cli::AddItemSem(),
                        _add_btn(new QPushButton("Add", this)),
                        _item_type(type),
                        _slide_index(slide_index) 
{
    setup_layout();
    setup_widgets();

    connect(_add_btn, &QPushButton::clicked, this, &AddItemWin::shape_item); 
}

void AddItemWin::shape_item()
{
    cli::RawArguments str_atributes;

    str_atributes["-t"] = _item_type;

    ////////////////////////////
    for (int i = 0; i < _atribute_layout->count(); ++i) {
        QLayoutItem *item = _atribute_layout->itemAt(i);
        if (item->widget()) {
            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(item->widget());
            if (lineEdit) {
                QString opt_name = lineEdit->property("opt_type").toString();
                str_atributes[opt_name.toStdString()] = lineEdit->text().toStdString();
            }
        }
    }
    for (int i = 0; i < _geometery_layout->count(); ++i) {
        QLayoutItem *item = _geometery_layout->itemAt(i);
        if (item->widget()) {
            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(item->widget());
            if (lineEdit) {
                QString opt_name = lineEdit->property("opt_type").toString();
                str_atributes[opt_name.toStdString()] = lineEdit->text().toStdString();
            }
        }
    }
    ////////////////////////////
    
    process_args(str_atributes);

    int x = std::get<int>(_geometery["-x"]);
    int y = std::get<int>(_geometery["-y"]);
    int w = std::get<int>(_geometery["-w"]);
    int h = std::get<int>(_geometery["-h"]);

    auto item = std::make_shared<model::Item>(x, y, w, h, _atributes);
    auto add_action = std::make_shared<core::AddItemAction>(item, std::get<int>(_atributes["-i"]));
    core::Editor::get_instance().process_action(add_action);
};

void AddItemWin::setup_widgets()
{
    if (!_atribute_layout || !_geometery_layout)
        throw std::runtime_error("gui: attribute or geometery layout not setted.");
    for (auto&& option : cli::AddItemCom::s_valid_shape_atributes.at(_item_type))
    {
        if (option != "-t"){
            QLabel * label = new QLabel(QString::fromStdString("Enter text: " + option + " "), this);
            QLineEdit* lineEdit = new QLineEdit(this);

            lineEdit->setProperty("opt_type", option.c_str());

            _atribute_layout->addWidget(label); 
            _atribute_layout->addWidget(lineEdit);
        }
    }
    for (auto&& option : cli::AddItemCom::s_valid_geometry)
    {
        QLabel * label = new QLabel (QString::fromStdString("Enter text: " + option + " "), this);
        QLineEdit* lineEdit = new QLineEdit(this);

        lineEdit->setProperty("opt_type", option.c_str());

        _geometery_layout->addWidget(label); 
        _geometery_layout->addWidget(lineEdit); 
    }
    _main_layout->addWidget(_add_btn);
};

void AddItemWin::setup_layout()
{
    QWidget* central = new QWidget(this);
    setCentralWidget(central);
    central->setStyleSheet("background-color: lightgray;");

    _main_layout = new QVBoxLayout;
    _geometery_layout = new QHBoxLayout;
    _atribute_layout = new QHBoxLayout;

    _main_layout->addLayout(_geometery_layout);
    _main_layout->addLayout(_atribute_layout);

    centralWidget()->setLayout(_main_layout);
};


