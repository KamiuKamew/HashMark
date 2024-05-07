#include "Iqhashcompiler.h"
#include "compiler.h"
#include <QDebug>

// 添加变量
void QCAddVar(QString name, double value) {
    Comp_addVar(name.toStdString().c_str(), value);
}

// 清除所有变量
void QCClearVars() {
    Comp_clearVars();
}

qsizetype QCGetNumVar(){
    return Comp_getNumVar();
}

double QCGetVar(qsizetype index, QString& name){
    char **s=new char*;
    double value;
    value = Comp_getVar(index, s);  // REMINDER::这一步有大问题，会在这一步出错。
    if(s==NULL){
        qDebug()<<"IN QHASHCOMPILER QCGETVAR:: null name";
        return 0;
    }
    name = QString::fromStdString(s[0]);
    delete s;
    return value;
}

// 评估表达式
void QCEvalExprs(QString expressions) {
    Comp_evalExprs(expressions.toStdString().c_str());
}

// 获取表达式结果
QVector<QString> QCGetExprnResults() {
    size_t* length=new size_t;
    const char** results = Comp_getExprnResults(length);
    QVector<QString> qResults;
    for (size_t i = 0; i < *length; ++i) {
        qResults.append(QString::fromStdString(results[i]));
    }
    delete length;
    return qResults;
}

// 清除表达式结果
void QCClearExprResults() {
    Comp_clearExprResults();
}
