#include "hsexprcomponents.h"

HsExprComponents& HsExprComponents::GetInstance(){
    static HsExprComponents instance;
    return instance;
}

void HsExprComponents::Clear(){
    Variables.clear();
    Functions.clear();
}
