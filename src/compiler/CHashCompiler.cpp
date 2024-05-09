#include "CHashCompiler.h"
#include "compiler.h"
#include <string>
#include <vector>

// 添加变量
void CHAddVar(std::string name, double value) {
    Comp_addVar(name.c_str(), value);
}

// 清除所有变量
void CHClearVars() {
    Comp_clearVars();
}

// 评估表达式
void CHEvalExprs(std::string expressions) {
    Comp_evalExprs(expressions.c_str());
}

// 获取表达式结果
std::vector<std::string> CHGetExprnResults(size_t* length) {
    const char** results = Comp_getExprnResults(length);
    std::vector<std::string> cResults;
    for (size_t i = 0; i < *length; ++i) {
        cResults.push_back(std::string(results[i]));
    }
    return cResults;
}

// 清除表达式结果
void CHClearExprResults() {
    Comp_clearExprResults();
}
