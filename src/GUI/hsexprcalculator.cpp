#include "hsexprcalculator.h"
#include "hsexprcomponents.h"
#include "textseperated.h"

HsExprCalculator& HsExprCalculator::GetInstance(){
    static HsExprCalculator instance;
    return instance;
}

void HsExprCalculator::Calculate(){
    QVector<Variable>& vars = HsExprComponents::GetInstance().Variables;
    QVector<Function>& funcs = HsExprComponents::GetInstance().Functions;
    QVector<QString>& exprs = TextSeperated::GetInstance().expressions;


}
