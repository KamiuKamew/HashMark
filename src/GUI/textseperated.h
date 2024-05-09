#ifndef TEXTSEPERATED_H
#define TEXTSEPERATED_H

/*
 * 用于拆分文件为表达式，并存储拆分后的部分。
 * 从TextReaded读入content。
 * 对TextGenerated开放bodies。
 * 对HsExprCalculator开放expressions。
 */

#include <QString>
#include <QVector>

class TextSeperated
{
    friend class HsExprCalculator;
    friend class TextGenerated;
private:
    QString head;
    QVector<QString> bodies;
    QVector<QString> expressions;
    qint32 sepnum;
    TextSeperated(){}
public:
    static TextSeperated& GetInstance();
    void Seperate();
};

#endif // TEXTSEPERATED_H
