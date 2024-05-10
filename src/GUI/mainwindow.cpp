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
    CurrentFileName.clear();
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
        hsdebug<<"void filename.";
        hsdebug<<"file failed to open.\n";
        return;
    }
    CurrentFileName=fileName;
    TReadFile(fileName);
    TInitAll();
    TCalcAll();
    TWDispText(ui->textBrowser_Main);
    TWDispVars(ui->widget_Variable_Container);
    isFileOpened=true;
    hsdebug<<"file opened.\n";
}


QString GenerateSavedFile();

void MainWindow::on_action_FileSave_triggered()
{
    hsdebug<<"file saving ...";
    if(CurrentFileName.isEmpty()){
        hsdebug<<"no file opened";
        hsdebug<<"file failed to save.\n";
        return;
    }
    QFile file(CurrentFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) { // 使用 WriteOnly 和 Truncate 模式
        hsdebug << "saving path failed to open. errorString:" << file.errorString(); // 输出文件打开失败信息
        hsdebug<<"file failed to save.\n";
        return;
    }
    QTextStream out(&file);
    out << GenerateSavedFile(); // 将生成的内容写入文件
    if (out.status() != QTextStream::Ok) {
        hsdebug << "saving content failed to write to file."; // 检查并输出写入错误信息
        hsdebug<<"file failed to save.\n";
    }
    file.close();
    hsdebug<<"file saved.\n";
}


void MainWindow::on_action_FileSaveAs_triggered()
{
    hsdebug<<"file save-as-ing ...";
    QString fileName = QFileDialog::getSaveFileName(
        this, tr("Save File As"), "",
        tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty()){
        hsdebug<<"void filename.";
        hsdebug<<"file failed to save.\n";
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        hsdebug << "saving path failed to open. errorString:" << file.errorString();
        hsdebug<<"file failed to save.\n";
        return;
    }
    QTextStream out(&file);
    out << GenerateSavedFile();  // 将生成的内容写入文件
    if (out.status() != QTextStream::Ok) {
        hsdebug << "saving content failed to write to file.";
        hsdebug<<"file failed to save.\n";
    }
    file.close();
    hsdebug<<"file save-as-ed.\n";
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
    /*
     * 当变量被改变时：依次执行以下函数
     * hsvareditwidget :        组件的textchanged信号发出。
     * hsvareditwidget :        valuechanged被调用。
     * hsvareditwidget :        valueedited信号发出。
     * （hsvareditwidget ：        TWDispVars连接信号）此步并非在此执行。
     * mainwindow       :       on_action_value_edited被调用。
     * itext            ：       TCalcAll被调用。
     * itext            ：       TCCalc
     * hsexprcalculator :       calculate
     * itext            ：       TGenr
     */
}

QString GenerateSavedFile(){
    QString content;

    content="测试文本";

    hsdebug<<"savedfile generated. size ="<<content.size();
    return content;
}
