/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_FileOpen;
    QAction *action_FileSave;
    QAction *action_FileExport;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_EditRegion;
    QVBoxLayout *verticalLayout;
    QWidget *Layout_EditRegion_2;
    QVBoxLayout *Layout_EditRegion;
    QTextBrowser *textBrowser_Foreword;
    QWidget *Layout_Variable_2;
    QHBoxLayout *Layout_Variable;
    QWidget *widget_Variable_Container;
    QScrollBar *ScrollBar_Variable;
    QWidget *widget_ViewRegion;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser_Main;
    QMenuBar *menubar;
    QMenu *menu_File;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(696, 551);
        action_FileOpen = new QAction(MainWindow);
        action_FileOpen->setObjectName("action_FileOpen");
        action_FileSave = new QAction(MainWindow);
        action_FileSave->setObjectName("action_FileSave");
        action_FileExport = new QAction(MainWindow);
        action_FileExport->setObjectName("action_FileExport");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_EditRegion = new QWidget(centralwidget);
        widget_EditRegion->setObjectName("widget_EditRegion");
        verticalLayout = new QVBoxLayout(widget_EditRegion);
        verticalLayout->setObjectName("verticalLayout");
        Layout_EditRegion_2 = new QWidget(widget_EditRegion);
        Layout_EditRegion_2->setObjectName("Layout_EditRegion_2");
        Layout_EditRegion = new QVBoxLayout(Layout_EditRegion_2);
        Layout_EditRegion->setObjectName("Layout_EditRegion");
        textBrowser_Foreword = new QTextBrowser(Layout_EditRegion_2);
        textBrowser_Foreword->setObjectName("textBrowser_Foreword");
        textBrowser_Foreword->setMaximumSize(QSize(16777215, 200));

        Layout_EditRegion->addWidget(textBrowser_Foreword);

        Layout_Variable_2 = new QWidget(Layout_EditRegion_2);
        Layout_Variable_2->setObjectName("Layout_Variable_2");
        Layout_Variable = new QHBoxLayout(Layout_Variable_2);
        Layout_Variable->setObjectName("Layout_Variable");
        widget_Variable_Container = new QWidget(Layout_Variable_2);
        widget_Variable_Container->setObjectName("widget_Variable_Container");

        Layout_Variable->addWidget(widget_Variable_Container);

        ScrollBar_Variable = new QScrollBar(Layout_Variable_2);
        ScrollBar_Variable->setObjectName("ScrollBar_Variable");
        ScrollBar_Variable->setOrientation(Qt::Vertical);

        Layout_Variable->addWidget(ScrollBar_Variable);


        Layout_EditRegion->addWidget(Layout_Variable_2);


        verticalLayout->addWidget(Layout_EditRegion_2);


        horizontalLayout->addWidget(widget_EditRegion);

        widget_ViewRegion = new QWidget(centralwidget);
        widget_ViewRegion->setObjectName("widget_ViewRegion");
        verticalLayout_2 = new QVBoxLayout(widget_ViewRegion);
        verticalLayout_2->setObjectName("verticalLayout_2");
        textBrowser_Main = new QTextBrowser(widget_ViewRegion);
        textBrowser_Main->setObjectName("textBrowser_Main");

        verticalLayout_2->addWidget(textBrowser_Main);


        horizontalLayout->addWidget(widget_ViewRegion);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 696, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName("menu_File");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_FileOpen);
        menu_File->addAction(action_FileSave);
        menu_File->addAction(action_FileExport);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        MainWindow->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        action_FileOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
        action_FileSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
        action_FileExport->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
