#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Itext.h"
#include <qprocess.h>
#include <QHBoxLayout>
#include <QMessageBox>
#include "hsdebug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isFileOpened=false;
    TWSetMainWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_FileOpen_triggered()
{
    hsdebug<<"file opening ...";
    // 获取用户打开的文件的名称
    QString fileName = QFileDialog::getOpenFileName(
        this, "Open", QCoreApplication::applicationFilePath(), "*.txt");
    hsdebug<<"filename = "<<fileName;
    if(fileName.isEmpty()){
        hsdebug<<"void filename";
        return;
    }
    TReadFile(fileName);
    TInitAll();
    TCalcAll();
    TWDispText(ui->textBrowser_Main);
    TWDispVars(ui->widget_Variable_Container);
    isFileOpened=true;
    hsdebug<<"file opened.\n";
}


void MainWindow::on_action_FileSave_triggered()
{

}


void MainWindow::on_action_FileExport_triggered()
{
    if(isFileOpened == false){
        QMessageBox::warning(this, "警告", "未打开文件！");
        return;
    }
    QString textToSave = TGetGenr();
    QString filePath = QFileDialog::getSaveFileName(this, "保存文件", QDir::homePath(), "文本文件 (*.txt)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textToSave;
            file.close();
            QMessageBox::information(this, "提示", "保存成功！");
        } else {
            QMessageBox::warning(this, "警告", "无法保存文件！");
        }
    }
}

// 自定义的槽函数。
// 信号来自HsVarEditComponent的valueEdited，当变量被改变时触发。
// 信号连接自Itext的TWDispVars，在VarEditComponents被生成的时候便进行连接。
void MainWindow::on_action_value_edited(){
    HSDebug<<"variable value edited.";
    TCalcAll();
    TWDispText(ui->textBrowser_Main);
}

