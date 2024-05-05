#ifndef CCOMP_H
#define CCOMP_H

#include <string>
#include <vector>
using namespace std;

void ccAddVar(string name, double value);
void ccClearVars();
void ccEvalExprs(string expressions);
vector<string> ccGetExprnResults(size_t* length);
void ccClearExprResults();

#endif
