#ifndef ADD_ITEM_WIN_HPP
#define ADD_ITEM_WIN_HPP

#include "add_item_sem.hpp"
#include "qmainwindow.h"
#include "qwidget.h"
#include <QGraphicsItem>
#include <QMainWindow>
#include <QItemEditorCreator>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>
 #include <QHBoxLayout>

namespace gui 
{

class AddItemWin : public QMainWindow
{
Q_OBJECT
public:
    AddItemWin(const std::string& type, int slide_index, QWidget* parent = nullptr);
private:
    void setup_layout();
    void setup_widgets();
    void shape_item(); 
    
    cli::AddItemSem _sem_analizer;
    QHBoxLayout*    _atribute_layout;  
    QHBoxLayout*    _geometery_layout;  
    QVBoxLayout*    _main_layout;  
    QPushButton*    _add_btn;
    std::string     _item_type;
    int             _slide_index;
};
}
#endif //add_item_win.hpp
