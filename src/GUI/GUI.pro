QT       += core gui
INCLUDEPATH += $$PWD/../compiler

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Iqhashcompiler.cpp \
    Itext.cpp \
    hsdebug.cpp \
    hsexprcalculator.cpp \
    hsexprcomponents.cpp \
    hsvareditwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    textgenerated.cpp \
    textreaded.cpp \
    textseperated.cpp \
    $$PWD/../compiler/lex.yy.c \
    $$PWD/../compiler/y.tab.c \
    $$PWD/../compiler/var.c \
    $$PWD/../compiler/ExpressionResults.cpp \
    $$PWD/../compiler/yyerror.c \
    $$PWD/../compiler/compiler.c

HEADERS += \
    Iqhashcompiler.h \
    Itext.h \
    hsdebug.h \
    hsexprcalculator.h \
    hsexprcomponents.h \
    hsvareditwidget.h \
    mainwindow.h \
    textgenerated.h \
    textreaded.h \
    textseperated.h \
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
