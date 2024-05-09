#include "Iqhashcompiler.h"
#include "compiler.h"
#include "hsdebug.h"

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
        hsdebug<<"null name";
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
QVector<QString> QCGetExprResults(){
    size_t* resnum=new size_t;
    const char** results = Comp_getExprnResults(resnum);
    hsdebug<<"resnum ="<<*resnum;
    QVector<QString> qResults;
    for (size_t i = 0; i < *resnum; ++i) {
        qResults.append(QString::fromStdString(results[i]));
    }
    delete resnum;
    return qResults;
}
QVector<QString> QCGetExprResults(QVector<bool> isEmptyList) {
    size_t* resnum=new size_t;
    const char** results = Comp_getExprnResults(resnum);
    hsdebug<<"resnum ="<<*resnum;
    /*
     * 这里的resnum是返回的表达式值的个数。
     * 由于下面的特性，resnum<=exprnum==sepnum。
     * 注意这里有个特性：
     * 空表达式不会返回值。
     * 因此这里需要传入空表达式列表isEmptyList
     * 当某个下标对应的表达式为空时：
     * 返回的qResults在这里为空。
     */
    QVector<QString> qResults;
    qsizetype resindex=0;
    for (qsizetype i = 0; i < isEmptyList.size(); ++i) {
        if(isEmptyList[i])
            qResults.append("");
        else
            qResults.append(QString::fromStdString(results[resindex++]));
    }
    delete resnum;
    return qResults;
}

// 清除表达式结果
void QCClearExprResults() {
    Comp_clearExprResults();
}
