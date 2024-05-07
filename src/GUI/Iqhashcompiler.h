#ifndef QHASHCOMPILER_H
#define QHASHCOMPILER_H

/*
 * 这是一个Qt图形界面和F&B编译器的桥梁，
 *  将F&B的接口中的C风格函数转换成Qt风格。
 *  本质上是一个对Qt特化的接口。
 * 仅对HsExprCalculator开放。
 * （当然，也对调试用main开放。）
 */

#include <QString>
#include <QVector>
using namespace std;

void QCAddVar(QString name, double value);
void QCClearVars();
qsizetype QCGetNumVar();
double QCGetVar(qsizetype index, QString& name);
void QCEvalExprs(QString expressions);
QVector<QString> QCGetExprnResults();
void QCClearExprResults();

#endif // QHASHCOMPILER_H
