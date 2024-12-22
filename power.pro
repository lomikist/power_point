TEMPLATE = app
TARGET = power

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20


QMAKE_CXXFLAGS += -fmax-errors=5
QMAKE_CXXFLAGS += -fdiagnostics-color=always

INCLUDEPATH += \
    $$PWD/cli/inc \
    $$PWD/cli/inc/factory \
    $$PWD/cli/inc/observer \
    $$PWD/cli/inc/semantic \
    $$PWD/core/inc \
    $$PWD/core/inc/observer \
    $$PWD/core/inc/logger \
    $$PWD/core/inc/vizualize \
    $$PWD/core/inc/editor \
    $$PWD/core/inc/vizualize/factory \
    $$PWD/model/inc \
    $$PWD/model/inc/factory \
    $$PWD/gui/inc

SOURCES += \
    $$files($$PWD/cli/src/*.cpp) \
    $$files($$PWD/cli/src/factory/*.cpp) \
    $$files($$PWD/cli/src/observer/*.cpp) \
    $$files($$PWD/cli/src/semantic/*.cpp) \
    $$files($$PWD/core/src/*.cpp) \
    $$files($$PWD/core/src/observer/*.cpp) \
    $$files($$PWD/core/src/logger/*.cpp) \
    $$files($$PWD/core/src/vizualize/*.cpp) \
    $$files($$PWD/core/src/editor/*.cpp) \
    $$files($$PWD/core/src/vizualize/factory/*.cpp) \
    $$files($$PWD/model/src/*.cpp) \
    $$files($$PWD/model/src/factory/*.cpp) \
    $$files($$PWD/gui/src/*.cpp) \
    $$PWD/main.cpp

HEADERS += \
    $$files($$PWD/cli/inc/*.hpp) \
    $$files($$PWD/cli/inc/factory/*.hpp) \
    $$files($$PWD/cli/inc/observer/*.hpp) \
    $$files($$PWD/cli/inc/semantic/*.hpp) \
    $$files($$PWD/core/inc/*.hpp) \
    $$files($$PWD/core/inc/observer/*.hpp) \
    $$files($$PWD/core/inc/logger/*.hpp) \
    $$files($$PWD/core/inc/vizualize/*.hpp) \
    $$files($$PWD/core/inc/editor/*.hpp) \
    $$files($$PWD/core/src/vizualize/factory/*.hpp) \
    $$files($$PWD/model/inc/*.hpp) \
    $$files($$PWD/model/inc/factory/*.hpp) \
    $$files($$PWD/gui/inc/*.hpp) \

FORMS   += $$files($$PWD/gui/form/*.ui)

QMAKE_CXXFLAGS += -std=c++20
