QT       += core gui
INCLUDEPATH += $$PWD/../compiler

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QHashCompiler.cpp \
    hsexprcalculator.cpp \
    hsexprcomponents.cpp \
    main.cpp \
    mainwindow.cpp \
    processor_ExpressionCalculator.cpp \
    processor_FileSeparator.cpp \
    processor_Main.cpp \
    processor_MainwindowLinker.cpp \
    textgenerated.cpp \
    textreaded.cpp \
    textseperated.cpp \
    widget_VariableEditor.cpp \
    $$PWD/../compiler/lex.yy.c \
    $$PWD/../compiler/y.tab.c \
    $$PWD/../compiler/var.c \
    $$PWD/../compiler/ExpressionResults.cpp \
    $$PWD/../compiler/yyerror.c \
    $$PWD/../compiler/compiler.c

HEADERS += \
    QHashCompiler.h \
    hsexprcalculator.h \
    hsexprcomponents.h \
    mainwindow.h \
    processors.h \
    textgenerated.h \
    textreaded.h \
    textseperated.h \
    widget_VariableEditor.h \
    $$PWD/../compiler/y.tab.h \
    $$PWD/../compiler/var.h \
    $$PWD/../compiler/ExpressionResults.h \
    $$PWD/../compiler/yyerror.h \
    $$PWD/../compiler/compiler.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
