#include "controller.hpp"
#include "qapplication.h"
#include <memory>
#include <QApplication>

int main (int argc, char *argv[])
{ 
    QApplication app(argc, argv);

    core::Controller& controller = core::Controller::get_instance();

    return app.exec();
}

