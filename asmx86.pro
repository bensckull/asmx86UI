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
    Window/variablewidget.cpp

HEADERS  += asmx86/engine/register.hpp \
    asmx86/file/file.hpp \
    asmx86/parser/instruction.hpp \
    asmx86/parser/label.hpp \
    asmx86/parser/macro.hpp \
    asmx86/parser/parser.hpp \
    asmx86/parser/section.hpp \
    asmx86/parser/utils.hpp \
    Window/window.h \
    Window/codeeditor.h \
    Window/registerwidget.h \
    Window/variablewidget.h

