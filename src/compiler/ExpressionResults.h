/*
  这是一个有关表达式计算结果的文件。
    1.给parser用来存放表达式结果。
    2.给对外接口用来获取表达式结果并清空结果。
  这个文件对外开放三个函数接口：
    addExpressionResult：用于添加表达式结果
      --> 开放给parser
    getExpressionResults：用于获得表达式结果
      --> 开放给对外接口（目前没写）
    clearExpressionResults：用于清空表达式结果
      --> 开放给对外接口（目前没写）
*/

#ifndef EXPRESSION_RESULTS_H
#define EXPRESSION_RESULTS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// 提供给C语言调用的接口函数
void addExpressionResult(double value);
const char** getExpressionResults(size_t* length);
void clearExpressionResults();

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <vector>
#include <string>

using namespace std;

// ExpressionResults类只在C++环境中定义
class ExpressionResults {
private:
  vector<string> results;  // 存储表达式计算结果的字符串
  ExpressionResults(){}  // 构造函数私有化

public:
  static ExpressionResults& getExpressionResultsInstance();  // 获取全局唯一实例的函数
  void addResult(double value);  // 添加一个计算结果
  const vector<string>& getResults() const;  // 获取所有结果
  void clearResults();  // 清除所有结果
};

#endif // __cplusplus

#endif // EXPRESSION_RESULTS_H
