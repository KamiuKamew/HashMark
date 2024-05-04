// var.c

#include <string.h>
#include <stdlib.h>
#include "yyerror.h"
#include "var.h"  // 包含符号表结构和常量的定义

int nsym=0;
struct symtab symtab[NSYMS];

struct symtab *symlook(char *s) {
    for (int i = 0; i < nsym; ++i) {
        if (!strcmp(symtab[i].name, s)) {  // 检查变量名是否已存在
            return &symtab[i];  // 返回存在的变量的地址
        }
    }

    if (nsym < NSYMS) {  // 检查是否还有空间添加新变量
        symtab[nsym].name = strdup(s);  // 复制变量名
        symtab[nsym].value = 0;  // 初始化变量值
        return &symtab[nsym++];  // 返回新变量的地址并更新变量数量
    }

    yyerror("Too many symbols");  // 错误处理：符号表已满
    exit(1);  // 异常退出
}

void addVariable(const char* name, double value) {
    struct symtab* sym = symlook(name);
    sym->value = value;
}

void clearVariables(){
    for(int i=0; i<nsym; i++){
        symtab[i].name="";
        symtab[i].value=0;
    }
}