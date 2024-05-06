// #include "mainwindow.h"
// #include "test.h"
// #include "qhashcompiler.h"

// #include <QApplication>
// #include <QWidget>
// #include <QHBoxLayout>
// #include <QVBoxLayout>
// #include <QLineEdit>
#include <QDebug>

// int main(int argc, char *argv[])
// {
//     // QApplication a(argc, argv);
//     // MainWindow w;
//     // w.show();

//     // return a.exec();

//     QCoreApplication app(argc, argv);
//     QTextStream qin(stdin), qout(stdout);
//     QString ipt;

//     qDebug()<<"start test:\n";

//     while (true) {
//         qin >> ipt;
//         if (ipt == "clv") {
//             QCClearVars();
//             continue;
//         }
//         if (ipt == "adv") {
//             QString name;
//             double value;
//             qin >> name >> value;
//             QCAddVar(name, value);
//             continue;
//         }
//         if (ipt == "gtv") {
//             qsizetype numVar = QCGetNumVar();
//             qout << "tot vars have " << numVar << '\n';

//             qsizetype index;
//             qin >> index;
//             QString name;
//             double value = QCGetVar(index, name);
//             qout << name << ": " << value << '\n';
//             continue;
//         }
//         QCEvalExprs(ipt);
//         size_t length;
//         QVector<QString> results = QCGetExprnResults(&length);
//         for (size_t i = 0; i < length; ++i) {
//             qout << results[i] << Qt::endl;  // Print all results
//         }
//         QCClearExprResults();
//     }
//     return app.exec();
//     return 0;
// }
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include "qhashcompiler.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt Command Processor Example");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QLabel *label = new QLabel("Enter commands:");
    QLineEdit *lineEdit = new QLineEdit;
    QTextEdit *textEdit = new QTextEdit;
    textEdit->setReadOnly(true);

    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(textEdit);

    QObject::connect(lineEdit, &QLineEdit::returnPressed, [&]() {
        QString input = lineEdit->text();
        textEdit->append("Command: " + input);

        if (input == "clv") {
            QCClearVars();
            textEdit->append("Variables cleared.");
        } else if (input.startsWith("adv")) {
            QStringList parts = input.split(' ');
            if (parts.size() == 3) {
                QString name = parts[1];
                double value = parts[2].toDouble();
                QCAddVar(name, value);
                textEdit->append("Variable added: " + name);
            }
        } else if (input.startsWith("gtv")) {
            qsizetype numVar = QCGetNumVar();
            textEdit->append("Total vars have: " + QString::number(numVar));
            QStringList parts = input.split(' ');
            if (parts.size() == 2) {
                qsizetype index = parts[1].toInt();
                QString name;
                qDebug()<<"get start";
                double value = QCGetVar(index, name);
                qDebug()<<"get done";
                textEdit->append("Variable name: " + name);
                textEdit->append("Variable value: " + QString::number(value));
            }
        } else {
            QCEvalExprs(input);
            size_t length;
            QVector<QString> results = QCGetExprnResults(&length);
            for (size_t i = 0; i < length; ++i) {
                textEdit->append(results[i]);
            }
            QCClearExprResults();
        }
        lineEdit->clear();
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}
