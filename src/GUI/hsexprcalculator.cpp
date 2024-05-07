#include "hsexprcalculator.h"
#include "hsexprcomponents.h"
#include "textseperated.h"

#include "Iqhashcompiler.h"

HsExprCalculator& HsExprCalculator::GetInstance(){
    static HsExprCalculator instance;
    return instance;
}

void HsExprCalculator::Initialize(){
    QVector<Variable>& vars = HsExprComponents::GetInstance().Variables;
    QVector<Function>& funcs = HsExprComponents::GetInstance().Functions;
    QVector<QString>& exprs = TextSeperated::GetInstance().expressions;
    qsizetype exprnum = TextSeperated::GetInstance().sepnum;
    
    QCClearVars();
    QCClearExprResults();
    
    for(qsizetype index=0; index<exprnum; index++){
        QCEvalExprs(exprs[index]);
    }
    
    qsizetype varnum = QCGetNumVar();
    
    for(qsizetype index=0; index<varnum; index++){
        QString name;
        double value=QCGetVar(index, name);                         // xuyaogai
        vars.push_back({name, QString::number(value)});
    }
    
    QCClearVars();
    QCClearExprResults();
}

void HsExprCalculator::Calculate(){
    QVector<QString>& exprs = TextSeperated::GetInstance().expressions;
    QVector<Variable>& vars = HsExprComponents::GetInstance().Variables;

    QCClearVars();
    QCClearExprResults();

    for(qsizetype index=0; index<vars.size(); index++){
        QCAddVar(vars[index].Name, vars[index].Value.toDouble());   //后面需要改一下。毕竟不能只传入数字，还应该可以传入字符。
    }

    for(qsizetype index=0; index<exprs.size(); index++){
        QCEvalExprs(exprs[index]);
    }
    
    results=QCGetExprnResults();

    QCClearVars();
    QCClearExprResults();
}
