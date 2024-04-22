%{
#include "parser.tab.h"  // Bison生成的头文件
%}

%%

[0-9]+(\.[0-9]+)?   { yylval.fval = atof(yytext); return NUMBER; }  // 浮点数
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.sval = strdup(yytext); return IDENTIFIER; }  // 标识符

"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return MULT; }
"/"     { return DIV; }
"^"     { return POW; }
"%"     { return MOD; }
"("     { return LPAREN; }
")"     { return RPAREN; }

[ \t]+  ;  // 忽略空白
\n      { return EOL; }  // 行结束
.       { return *yytext; }  // 其他字符

%%
