/*
    由于parser和var都需要yyerror
    所以单独把yyerror写成一个头文件
    方便各方调用。

    更新：
    由于未知的原因，现在每次输入后程序都会返回syntax error，
    我修不好就干脆把yyerror禁用了。
*/
#ifndef __YYERROR
#define __YYERROR
void yyerror(const char* msg);
#endif