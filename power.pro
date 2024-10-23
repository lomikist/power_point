
# Specify project type
TEMPLATE = app
TARGET = power

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Set C++ standard
CONFIG += c++20

# Include directories
INCLUDEPATH += \
    $$PWD/cli/inc \
    $$PWD/cli/inc/factory \
    $$PWD/cli/inc/observer \
    $$PWD/controller/inc \
    $$PWD/controller/inc/observer \
    $$PWD/model/inc \
    $$PWD/model/inc/factory \
    $$PWD/gui/inc

# Source files (recursively gathering all .cpp files)
SOURCES += \
    $$files($$PWD/cli/src/*.cpp) \
    $$files($$PWD/cli/src/factory/*.cpp) \
    $$files($$PWD/cli/src/observer/*.cpp) \
    $$files($$PWD/controller/src/*.cpp) \
    $$files($$PWD/controller/src/observer/*.cpp) \
    $$files($$PWD/model/src/*.cpp) \
    $$files($$PWD/model/src/factory/*.cpp) \
    $$files($$PWD/gui/src/*.cpp) \
    $$PWD/main.cpp

# Header files (optional: you can list them explicitly if needed)
HEADERS += \
    $$files($$PWD/cli/inc/*.hpp) \
    $$files($$PWD/cli/inc/factory/*.hpp) \
    $$files($$PWD/cli/inc/observer/*.hpp) \
    $$files($$PWD/controller/inc/*.hpp) \
    $$files($$PWD/controller/inc/observer/*.hpp) \
    $$files($$PWD/model/inc/*.hpp) \
    $$files($$PWD/model/inc/factory/*.hpp) \
    $$files($$PWD/gui/inc/*.hpp) \

FORMS   += $$files($$PWD/gui/form/*.ui)

# Compiler flags for C++20
QMAKE_CXXFLAGS += -std=c++20

