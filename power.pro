TEMPLATE = app
TARGET = power

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

CONFIG(debug, debug|release): {
    CONFIG += debug
    QMAKE_RUN_ENV += QT_DEBUG_PLUGINS=1
}

QMAKE_CXXFLAGS += -fmax-errors=5
QMAKE_CXXFLAGS += -fdiagnostics-color=always

INCLUDEPATH += \
    $$PWD/cli/inc \
    $$PWD/cli/inc/factory \
    $$PWD/cli/inc/observer \
    $$PWD/controller/inc \
    $$PWD/controller/inc/observer \
    $$PWD/controller/inc/logger \
    $$PWD/controller/inc/vizualize \
    $$PWD/model/inc \
    $$PWD/model/inc/factory \
    $$PWD/gui/inc

SOURCES += \
    $$files($$PWD/cli/src/*.cpp) \
    $$files($$PWD/cli/src/factory/*.cpp) \
    $$files($$PWD/cli/src/observer/*.cpp) \
    $$files($$PWD/controller/src/*.cpp) \
    $$files($$PWD/controller/src/observer/*.cpp) \
    $$files($$PWD/controller/src/logger/*.cpp) \
    $$files($$PWD/controller/src/vizualize/*.cpp) \
    $$files($$PWD/model/src/*.cpp) \
    $$files($$PWD/model/src/factory/*.cpp) \
    $$files($$PWD/gui/src/*.cpp) \
    $$PWD/main.cpp

HEADERS += \
    $$files($$PWD/cli/inc/*.hpp) \
    $$files($$PWD/cli/inc/factory/*.hpp) \
    $$files($$PWD/cli/inc/observer/*.hpp) \
    $$files($$PWD/controller/inc/*.hpp) \
    $$files($$PWD/controller/inc/observer/*.hpp) \
    $$files($$PWD/controller/inc/logger/*.hpp) \
    $$files($$PWD/controller/inc/vizualize/*.hpp) \
    $$files($$PWD/model/inc/*.hpp) \
    $$files($$PWD/model/inc/factory/*.hpp) \
    $$files($$PWD/gui/inc/*.hpp) \

FORMS   += $$files($$PWD/gui/form/*.ui)

QMAKE_CXXFLAGS += -std=c++20
