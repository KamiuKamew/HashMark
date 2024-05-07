#ifndef ITEXT_H
#define ITEXT_H

/*
 * 这是文本处理部分与图形化界面的接口。
 * 所有函数都仅对MainWindow开放。
 */

#include <QString>

//TextReaded
void TReadFile(const QString &fileName);

//TextSeperated
void TSepr();

//HsExprCalculator
void TCInit();
void TCCalc();

//HsRxprComponents;
void TCCompClear();
//friend QVector<Variable>& TGetVars();

//TextGenerated
void TGenr();
//friend QString TGetGenr();

//Itext
void TInitAll();
void TCalcAll();

#endif // ITEXT_H
