%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yyerror.h"
#include "var.h"
#include "ExpressionResults.h"  // 包含新的接口头文件
int yylex();

%}

%union {
        double dval;
        char * varname;
}

%token <varname> NAME
%token <dval> NUMBER
%left '+' '-'
%left '*' '/'

%type <dval> expression

%%
statement_list : statement '\n'   
               |   statement_list statement '\n'
;

statement : NAME '=' expression {symlook($1)->value = $3; }
          | expression { addExpressionResult($1); }  // 使用接口添加结果
;

expression : expression '+' expression { $$ = $1 + $3; }
           |   expression '-' expression { $$ = $1 - $3; }
           |   expression '*' expression { $$ = $1 * $3; }
           |   expression '/' expression {
                                                if (($3) != 0.0 )
                                                $$ = $1 / $3;
                                                else
                                                 yyerror("divide by zero");
                                                }
           |   '(' expression ')' { $$ = $2; }
           |   NUMBER
           |   NAME {$$ = symlook($1)->value; }
;

%%

/*
    注；
    这里的main函数只是用来临时测试的
    后面main函数会换到Qt中。
*/

int main() {
    if (yyparse() == 0) { // Parse complete
        size_t length;
        const char **results = getExpressionResults(&length);
        for (size_t i = 0; i < length; ++i) {
            printf("%s\n", results[i]);  // Print all results
        }
        clearExpressionResults();
    }
    return 0;
}
