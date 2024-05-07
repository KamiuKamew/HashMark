#include "hsexprcomponents.h"

HsExprComponents& HsExprComponents::GetInstance(){
    static HsExprComponents instance;
    return instance;
}

void HsExprComponents::ComponentsClear(){
    Variables.clear();
    Functions.clear();
}
