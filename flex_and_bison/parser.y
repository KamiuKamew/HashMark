%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void yyerror(char *s);
int yylex(void);

%}

%union {
    float fval;
    char* sval;
}

%token <fval> NUMBER
%token <sval> IDENTIFIER
%token PLUS MINUS MULT DIV POW MOD LPAREN RPAREN EOL

%type <fval> expression
%type <sval> str_expression

%left PLUS MINUS
%left MULT DIV MOD
%right POW
%nonassoc LPAREN RPAREN

%%

program:
    | program line
    ;

line:
    expression EOL { printf("Result: %f\n", $1); }
  | str_expression EOL { printf("Result: %s\n", $1); free($1); }
  ;

expression:
    NUMBER                { $$ = $1; }
  | IDENTIFIER           { $$ = lookup_var($1); }  // 需要实现变量查找和存储逻辑
  | expression PLUS expression   { $$ = $1 + $3; }
  | expression MINUS expression  { $$ = $1 - $3; }
  | expression MULT expression   { $$ = $1 * $3; }
  | expression DIV expression    { $$ = $1 / $3; }
  | expression POW expression    { $$ = pow($1, $3); }
  | expression MOD expression    { $$ = fmod($1, $3); }
  | LPAREN expression RPAREN     { $$ = $2; }
  ;

str_expression:
    IDENTIFIER { $$ = strdup($1); }
  | str_expression PLUS expression { char buf[128]; sprintf(buf, "%s%f", $1, $3); $$ = strdup(buf); free($1); }
  | str_expression PLUS str_expression { char *result = malloc(strlen($1) + strlen($3) + 1); strcpy(result, $1); strcat(result, $3); $$ = result; free($1); free($3); }
  ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    printf("Enter expressions:\n");
    yyparse();
    return 0;
}
