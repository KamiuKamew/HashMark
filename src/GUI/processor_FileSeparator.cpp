// // FileSeparator:
// private:
//      QString fileHead; // 文件头
//      QVector<QString> fileBody; // 文件主体
//      QVector<QString> fileVariableName; // 文件变量名
//      QVector<QString> fileVariableValue; // 文件变量值
// public:
//      Processors(QObject *parent_input, const QString &fileName); // 构造函数，接受文件名作为参数
//      void fileSeparate(const QString &fileName);
//      QString joinFileBody(); // 拼接fileBody中的文本
//      void displayTextInBrowser(QTextBrowser *textBrowser); // 在textBrowser中显示拼接后的文本
//      void displayVariableInWidget(QWidget *rootWidget);

#include "processors.h"
#include <QFile>

Processors::Processors(QObject *parent_input, const QString &fileName):
    parent(parent_input),
    textBrowser(nullptr)
{
    fileSeparate(fileName);
}

void Processors::fileSeparate(const QString &fileName){
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << file.errorString(); // 输出文件打开失败信息
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {   // 对于每一段文字（以换行为界）：
        QString line=in.readLine();
        int dbHashStart = line.indexOf("##"); // double hash start
        int dbHashEnd = 0;
        int dbHashEnd_last = -2;
        while (dbHashStart != -1) {     // 对于每一个文本块和井号变量块：
            dbHashEnd = line.indexOf("##", dbHashStart + 2);
            if (dbHashEnd != -1) {

                QString BodyPiece = line.sliced(dbHashEnd_last + 2, dbHashStart - (dbHashEnd_last + 2));
                QString Expression = line.sliced(dbHashStart + 2, dbHashEnd - (dbHashStart + 2));

                fileBody.push_back(BodyPiece); // 将双井号之前的部分存入fileBody
                fileExpressions.push_back(Expression);
                // fileVariableName.push_back(fileExpression); // 将双井号之间的部分存入fileVariableName
                // fileVariableValue.push_back("");

                qDebug() << "fileBodyPiece: " << BodyPiece;
                qDebug() << "fileExpression: " << Expression;

                dbHashEnd_last = dbHashEnd;
                dbHashStart = line.indexOf("##", dbHashEnd + 2); // 查找下一个双井号的位置
            } else {

                //REMINDER: 这里写一个提示井号表达式不全的窗口，替换掉这个qdebug。

                qDebug() << "Incomplete hash sign expression";
                break;
            }
        }

        qDebug() << "fileBodyPiece: " << line.sliced(dbHashEnd_last+2) << " \\n";
        qDebug() << "fileExpression: " << "<void>";

        fileBody.push_back(line.sliced(dbHashEnd_last+2)+"\n");// 在每行文本后面添加换行符
        fileExpressions.push_back("");
        // fileVariableName.push_back("");
        // fileVariableValue.push_back("");
    }

    file.close();
}
