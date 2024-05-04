/*
    由于parser和var都需要yyerror
    所以单独把yyerror写成一个头文件
    方便各方调用。
*/
#ifndef __YYERROR
#define __YYERROR
void yyerror(const char* msg);
#endif