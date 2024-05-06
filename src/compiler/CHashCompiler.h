#ifndef CHASHCOMPILER_H
#define CHASHCOMPILER_H

#include "compiler.h"
#include <string>
#include <vector>

void CHAddVar(std::string name, double value);
void CHClearVars();
void CHEvalExprs(std::string expressions);
std::vector<std::string> CHGetExprnResults(size_t* length);
void CHClearExprResults();

#endif // CHASHCOMPILER_H
