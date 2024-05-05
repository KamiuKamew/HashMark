#include "mainwindow.h"
//#include "hashProcessor.h"

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // float f1=123,f2=123.00;
    // QString qs1=QString::number(f1);
    // QString qs2=QString::number(f2);
    // qDebug()<<qs1;
    // qDebug()<<qs2;

    return a.exec();
}

// in performOperation：
// REMINDER:
// 待完善：写一个东西别让它一直弹窗口。最好放到最上面的窗口里显示。
