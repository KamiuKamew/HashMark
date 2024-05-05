#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
void Comp_addVar(const char* name, double value);
void Comp_clearVars();
void Comp_evalExprs(const char* expressions);
const char** Comp_getExprnResults(size_t* length);
void Comp_clearExprResults();

#ifdef __cplusplus
}
#endif

#endif // COMPILER_H
