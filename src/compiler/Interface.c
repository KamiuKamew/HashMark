#include "Interface.h"
#include "y.tab.h"
#include "ExpressionResults.h"
#include "var.h"

void Comp_addVar(const char* name, double value){
    // var.h
    addVariable(name, value);
}

void Comp_clearVars(){
    // var.h
    clearVariables();
}

void Comp_evalExprs(const char* expressions){
    // lexer.l (lex.yy.c)
    evaluateExpressions(expressions);
}

const char** Comp_getExprnResults(size_t* length){
    // ExpressionResults.h
    getExpressionResults(length);
}

void Comp_clearExprResults(){
    // ExpressionResults.h
    clearExpressionResults();
}