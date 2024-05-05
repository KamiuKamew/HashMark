#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include "processors.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Processors *hsp;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_FileOpen_triggered();
    void on_action_FileSave_triggered();
    void on_action_FileExport_triggered();
};
#endif // MAINWINDOW_H
