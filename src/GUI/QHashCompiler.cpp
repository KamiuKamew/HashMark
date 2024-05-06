#include "QHashCompiler.h"
#include "compiler.h"

// 添加变量
void QCAddVar(QString name, double value) {
    Comp_addVar(name.toStdString().c_str(), value);
}

// 清除所有变量
void QCClearVars() {
    Comp_clearVars();
}

// 评估表达式
void QCEvalExprs(QString expressions) {
    Comp_evalExprs(expressions.toStdString().c_str());
}

// 获取表达式结果
QVector<QString> QCGetExprnResults(size_t* length) {
    const char** results = Comp_getExprnResults(length);
    QVector<QString> qResults;
    for (size_t i = 0; i < *length; ++i) {
        qResults.append(QString::fromStdString(results[i]));
    }
    return qResults;
}

// 清除表达式结果
void QCClearExprResults() {
    Comp_clearExprResults();
}
