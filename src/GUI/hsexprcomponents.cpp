#include "hsexprcomponents.h"

HsExprComponents& HsExprComponents::GetInstance(){
    static HsExprComponents instance;
    return instance;
}
