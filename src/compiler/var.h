/*
  这是一个专门存储及控制变量的文件
  这个文件只对外开放两个函数接口：
    symlook：用于查找变量及创建新的默认变量
      --> 开放给parser
    add_variable：用于创建新的变量（用于初始化）
      --> 开放给整体对外接口（目前没写）
*/
#ifdef __cplusplus
extern "C" {
#endif


#ifndef VAR_H
#define VAR_H

#define NSYMS 20 /* 允许的符号个数 */

struct symtab {
  char *name;     /* 变量名 */
  double value;   /* 变量值 */
};

struct symtab *symlook(char *s);
void add_variable(const char *name, double value); 

#endif


#ifdef __cplusplus
}
#endif