#ifndef QHASHCOMPILER_H
#define QHASHCOMPILER_H

#include <QString>
#include <QVector>
using namespace std;

void QCAddVar(QString name, double value);
void QCClearVars();
void QCEvalExprs(QString expressions);
QVector<QString> QCGetExprnResults(size_t* length);
void QCClearExprResults();

#endif // QHASHCOMPILER_H
