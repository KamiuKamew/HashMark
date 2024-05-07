#ifndef TEXTGENERATED_H
#define TEXTGENERATED_H

/*
 * 用于拼合并存储生成好的文本。
 * 从TextSeperated读取bodies。
 * 从HsExprCalculator读取results。
 * 向MainWindow开放content。
 */

#include <QString>

class TextGenerated
{
    friend QString TGetGenr();
private:
    QString content;
    TextGenerated(){}
public:
    static TextGenerated& GetInstance();
    void Generate();
};

#endif // TEXTGENERATED_H
