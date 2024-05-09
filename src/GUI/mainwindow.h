#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*
 * 显示出来的主要界面。
 * 主要与Itext中的函数交互。
 * 向Itext中部分函数开放友元权限。
 */

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow{
    Q_OBJECT
    friend void TWDispVars(QWidget *widget_Variable_Container);
private:
    Ui::MainWindow *ui;
    bool isFileOpened;
    QString CurrentFileName;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_FileOpen_triggered();
    void on_action_FileSave_triggered();
    void on_action_FileSaveAs_triggered();
    void on_action_FileExport_triggered();
    void on_action_value_edited();
};
#endif // MAINWINDOW_H
