// #include "mainwindow.h"
// #include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;
//     w.show();

//     return a.exec();
// }



#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include "Iqhashcompiler.h"
#include "hsdebug.h"

int main(int argc, char *argv[]) {
    HSDebug<<"test:1";
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
                double value = QCGetVar(index, name);
                textEdit->append("Variable name: " + name);
                textEdit->append("Variable value: " + QString::number(value));
            }
        } else {
            QCEvalExprs(input);
            QVector<QString> results = QCGetExprResults();
            for (size_t i = 0; i < results.size(); ++i) {
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
