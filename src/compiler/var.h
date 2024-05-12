/*
  这是一个专门存储及控制变量的文件
  这个文件对外开放五个函数接口：
    symlook：用于查找变量及创建新的默认变量
      --> 开放给parser
    addVariable：用于创建新的变量（用于初始化）
      --> 开放给整体对外接口compiler
    clearVariables：用于清除变量
      --> 开放给整体对外接口compiler
    getNumberOfVariable：用于获取变量个数
      --> 开放给整体对外接口compiler
    getVariable；用于获得某一变量
      --> 开放给整体对外接口compiler
*/
#ifdef __cplusplus
extern "C" {
#endif


#ifndef VAR_H
#define VAR_H

#define NSYMS 100 /* 允许的符号个�?*/

struct symtab {
  char *name;     /* 变量�?*/
  double value;   /* 变量�?*/
};

int issymcontain(char *s);
struct symtab *symlook(char *s);
void addVariable(const char *name, double value); 
void clearVariables();
size_t getNumberOfVariable();
double getVariable(size_t index, char **s);

#endif


#ifdef __cplusplus
}
#endif