#include "textreaded.h"
#include <QFile>
#include <QDebug>
#include "hsdebug.h"

TextReaded& TextReaded::GetInstance(){
    static TextReaded instance;
    return instance;
}

void TextReaded::Clear(){
    content.clear();
    fromFile.clear();
}

void TextReaded::ReadText(const QString &fileName){
    Clear();
    fromFile=fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        hsdebug<<"Failed to open file: " << file.errorString(); // 输出文件打开失败信息
        return;
    }
    QTextStream in(&file);
    content = in.readAll();
    file.close();
    hsdebug<<"file readed. size = "<<content.size();
}
