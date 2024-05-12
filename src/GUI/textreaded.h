#ifndef TEXTREADED_H
#define TEXTREADED_H

/*
 * 用于读取文件并存储。
 * 从Itext读入filename。
 * 对TextSeparator开放content。
 */

#include <QString>

class TextReaded{
    friend class TextSeperated;
private:
    QString content;
    QString fromFile;
    TextReaded(){}
public:
    static TextReaded& GetInstance();
    void Clear();
    void ReadText(const QString &fileName);
};

#endif // TEXTREADED_H
