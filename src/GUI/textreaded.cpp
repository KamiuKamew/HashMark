#include "textreaded.h"
#include <QFile>
#include <QDebug>

TextReaded& TextReaded::GetInstance(){
    static TextReaded instance;
    return instance;
}

void TextReaded::ReadText(const QString &fileName){
    content.clear();
    fromFile=fileName;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << file.errorString(); // 输出文件打开失败信息
        return;
    }
    QTextStream in(&file);
    content = in.readAll();
    file.close();
}
