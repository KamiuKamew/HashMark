#ifndef TEXTSEPERATED_H
#define TEXTSEPERATED_H

/*
 * 用于拆分文件为表达式，并存储拆分后的部分。
 * 从TextReaded读入content。
 * 对TextGenerated开放bodies。
 * 对HsExprCalculator开放expressions。
 * 对TGetHead开放head.
 * 对hscodegenerated开放head，bodies和expressions
 */

#include <QString>
#include <QVector>

class TextSeperated
{
    friend class HsExprCalculator;
    friend class TextGenerated;
    friend QString TGetHead();
    friend class HsCodeGenerated;
private:
    QString head;
    QVector<QString> bodies;
    QVector<QString> expressions;
    qint32 sepnum;
    TextSeperated(){}
public:
    static TextSeperated& GetInstance();
    void Clear();
    void Seperate();
};

#endif // TEXTSEPERATED_H
