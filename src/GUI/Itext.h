#ifndef ITEXT_H
#define ITEXT_H

/*
 * 这是文本处理部分与图形化界面的接口。
 * 从MainWindow中获得友元权限（个别函数）
 * 所有函数都仅对MainWindow开放。
 */

#include <QString>
#include <QTextBrowser>
#include <QObject>

//TextReaded
void TReadFile(const QString &fileName);

//TextSeperated
void TSepr();

//HsExprCalculator
void TCInit();
void TCCalc();

//HsRxprComponents;
void TCCompClear();
struct Variable;        // forward declaration of struct Variable
QVector<Variable>& TGetVars();

//TextGenerated
void TGenr();
QString TGetGenr();

//Itext-window
class MainWindow;       // forward declaration of struct Variable
void TWSetMainWindow(MainWindow *mw);
void TWDispText(QTextBrowser *Browser);
void TWDispVars(QWidget *widget_Variable_Container);

//Itext-text
void TInitAll();
void TCalcAll();

#endif // ITEXT_H
