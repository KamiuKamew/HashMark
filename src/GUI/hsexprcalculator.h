#ifndef HSEXPRCALCULATOR_H
#define HSEXPRCALCULATOR_H

/*
 * 用于计算井号表达式并存储计算结果。
 * 从TextSeperated读入expressions。
 * 调用QHashCompiler进行计算。
 * 从HsExprComponents获得Variables和Functions的引用。
 * 向TextGenerated开放Results。
 */

// REMINDER:: 这是重点部分，一会再写，先把其他的重构完先。

#include <QVector>
#include <QString>

class HsExprCalculator
{
    friend class TextGenerated;
private:
    QVector<QString> results;
    static HsExprCalculator& GetInstance();
public:
    void Calculate();
};

#endif // HSEXPRCALCULATOR_H
