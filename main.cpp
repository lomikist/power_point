#include "controller.hpp"
#include "qapplication.h"
#include <memory>
#include <QApplication>

int main (int argc, char *argv[])
{
    auto app = core::Controller(argc, argv);

    return app.instance()->exec();
}

