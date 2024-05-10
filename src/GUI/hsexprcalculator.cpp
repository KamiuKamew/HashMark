#include "hsexprcalculator.h"
#include "hsexprcomponents.h"
#include "textseperated.h"
#include "Iqhashcompiler.h"
#include "hsdebug.h"

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
    hsdebug<<"components initialized. varnum ="<<varnum;
}

void HsExprCalculator::Calculate(){
    QVector<QString>& exprs = TextSeperated::GetInstance().expressions;
    QVector<Variable>& vars = HsExprComponents::GetInstance().Variables;
    QVector<bool> isExprsEmpty;
    isExprsEmpty.resize(exprs.size());

    QCClearVars();
    QCClearExprResults();

    // 传入变量表
    HSDEBUG(hsCalcDebug)<<"import variable table:";
    for(qsizetype index=0; index<vars.size(); index++){
        QCAddVar(
            vars[index].Name,
            (vars[index].Value.isEmpty() ?
                0 :
                vars[index].Value.toDouble()
             )
         );   //后面需要改一下。毕竟不能只传入数字，还应该可以传入字符。
        HSDEBUG(hsCalcDebug)<<vars[index].Name<<'='<<vars[index].Value<<"of index"<<index;
    }

    // 传入表达式
    for(qsizetype index=0; index<exprs.size(); index++){
        QCEvalExprs(exprs[index]);
        isExprsEmpty[index]=exprs[index].isEmpty();
    }
    
    // 获取表达式值
    expressionResults=QCGetExprResults(isExprsEmpty);

    QCClearVars();
    QCClearExprResults();
    hsdebug<<"expression calculated. exprnum ="<<expressionResults.size();
}
