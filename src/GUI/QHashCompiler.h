#ifndef QHASHCOMPILER_H
#define QHASHCOMPILER_H

// REMINDER:: 这里还缺函数QCGetVars，读取所有的变量值。

#include <QString>
#include <QVector>
using namespace std;

void QCAddVar(QString name, double value);
void QCClearVars();
qsizetype QCGetNumVar();
double QCGetVar(qsizetype index, QString& name);
void QCEvalExprs(QString expressions);
QVector<QString> QCGetExprnResults(size_t* length);
void QCClearExprResults();

#endif // QHASHCOMPILER_H
