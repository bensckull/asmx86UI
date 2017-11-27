QT       += core gui

QT += widgets

TARGET = asmx86ui
TEMPLATE = app
CONFIG += c++14

INCLUDEPATH += asmx86

SOURCES += Window/window.cpp \
            main.cpp \
    Window/codeeditor.cpp \
    Window/registerwidget.cpp \
    Window/pile.cpp\
    Window/variablewidget.cpp

HEADERS  += asmx86/engine/register.hpp \
    asmx86/file/file.hpp \
    asmx86/engine/engine.hpp\
    asmx86/engine/register.hpp\
    asmx86/engine/stack.hpp\
    asmx86/engine/variable.hpp\
    asmx86/parser/instruction.hpp \
    asmx86/parser/label.hpp \
    asmx86/parser/macro.hpp \
    asmx86/parser/parser.hpp \
    asmx86/parser/section.hpp \
    asmx86/parser/utils.hpp \
    Window/window.h \
    Window/codeeditor.h \
    Window/registerwidget.h \
    Window/pile.h\
    Window/variablewidget.h

