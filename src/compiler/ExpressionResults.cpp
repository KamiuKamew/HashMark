#include "ExpressionResults.h"
#include <cstdio>  // For sprintf in C++

#ifdef __cplusplus

using namespace std;

// 单例模式实现，保证全局只有一个ExpressionResults实例
ExpressionResults& ExpressionResults::getExpressionResultsInstance() {
    static ExpressionResults instance;
    return instance;
}

// 添加一个结果到vector�?
void ExpressionResults::addResult(double value) {
    char buffer[50];
    sprintf(buffer, "%lf", value);
    results.push_back(string(buffer));
}

// 返回当前所有的结果
const vector<string>& ExpressionResults::getResults() const {
    return results;
}

// 清空所有结�?
void ExpressionResults::clearResults() {
    results.clear();
}

#endif // __cplusplus

// C语言接口实现
void addExpressionResult(double value) {
    ExpressionResults::getExpressionResultsInstance().addResult(value);
}

const char** getExpressionResults(size_t* length) {
    static const char* resultsArray[100];  // Adjust size as needed
    const vector<string>& results = ExpressionResults::getExpressionResultsInstance().getResults();
    *length = results.size();
    for (size_t i = 0; i < *length; ++i) {
        resultsArray[i] = results[i].c_str();
    }
    return resultsArray;
}

void clearExpressionResults() {
    ExpressionResults::getExpressionResultsInstance().clearResults();
}
