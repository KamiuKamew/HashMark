#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <qprocess.h>
#include <QHBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hsp=nullptr;
    //connect signals to slot functions:
    //grammar: connect(ui-><composition>(the Sender), &<className>::<signal_kind>(which signal), this(the Dealer), &MainWindow::<slot func>)
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_FileOpen_triggered()
{
    // 获取用户打开的文件的名称
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QCoreApplication::applicationFilePath(), "*.txt");
    // 创建“井号表达式处理者”对象
    hsp = new Processors(this, fileName);
    // 将原始表达式显示出来
    hsp->displayTextInBrowser(ui->textBrowser_Main);
    hsp->displayVariableInWidget(ui->widget_Variable_Container);
}


void MainWindow::on_action_FileSave_triggered()
{

}


void MainWindow::on_action_FileExport_triggered()
{
    if(hsp == nullptr){
        //qDebug()<<"nullsaveptr";
        QMessageBox::warning(this, "警告", "未打开文件！");
        return;
    }
    QString textToSave = hsp->joinFileBody();
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

