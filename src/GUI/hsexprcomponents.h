#ifndef HSEXPRCOMPONENTS_H
#define HSEXPRCOMPONENTS_H

/*
 * 用于定义并存放井号表达式的组件（变量与函数）
 * 对HsExprCalculator开放全部。
 * 对HsVarEditWidget开放Variables
 * 对Itext开放TGetVars，可以手动输入变量值。
 * 对Itext开放RemoveAll，可以删除所有变量及函数。
 */

#include "hsdebug.h"
#include <QVector>
#include <QString>

struct Function{
    QString Name; // 函数名
    QList<QString> arguments; // 参数列表
    QString expression; // 表达式

    Function(QString n, QList<QString> a, QString e):
        Name(n),
        arguments(a),
        expression(e){
        qDebug() << "function created: "+n;
    }
};
struct Variable{
    QString Name;
    QString Value;

    Variable(QString n, QString v):
        Name(n),
        Value(v){
        HSDebug << "variable created:"<<n<<"with value"<<v;
    }
    friend bool operator==(Variable v1, const QString qs){
        return v1.Name == qs;
    }
};

class HsExprComponents
{
    friend class HsExprCalculator;
    friend class HsVarEditWidget;
    friend QVector<Variable>& TGetVars();
private:
    QVector<Variable> Variables; // 变量（名-值）
    QVector<Function> Functions; // 函数（名-值列表-表达式）
    HsExprComponents(){}
public:
    static HsExprComponents& GetInstance();
    void ComponentsClear();
};

#endif // HSEXPRCOMPONENTS_H
