#ifndef HSEXPRCOMPONENTS_H
#define HSEXPRCOMPONENTS_H

/*
 * 用于定义并存放井号表达式的组件（变量与函数）
 * 对HsExprCalculator开放全部。
 * 对MainWindow开放Variables，可以手动输入变量值。
 */

#include <QDebug>
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
        qDebug() << "variable created: "<<n<<"with walue"<<v;
    }
    friend bool operator==(Variable v1, const QString qs){
        return v1.Name == qs;
    }
};

class HsExprComponents
{
    friend class HsExprCalculator;
private:
    QVector<Variable> Variables; // 变量（名-值）
    QVector<Function> Functions; // 函数（名-值列表-表达式）
    HsExprComponents(){}
public:
    static HsExprComponents& GetInstance();
};

#endif // HSEXPRCOMPONENTS_H
