%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "var.h"
int nsym = 0;
struct symtab symtab[NSYMS];
int yylex();
void yyerror(const char* msg);
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
          | expression { printf("= %lf\n", $1); }
;

expression : expression '+' expression { $$ = $1 + $3; }
           |   expression '-' expression { $$ = $1 - $3; }
           |   expression '*' expression { $$ = $1 * $3; }
           |   expression '/' expression        {
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

struct symtab * symlook(char *s)
{
        int i;

        for (i = 0; i < nsym; ++i) {
                if (!strcmp(symtab[i].name, s))
                {
                        printf("found variable.\n");
                        return &symtab[i];
                }
        }

        if (nsym < NSYMS) {
                symtab[nsym].name = strdup(s);
                ++nsym;
                return &symtab[nsym-1];
        }

        yyerror("Too many symbols");
        exit(1);
}

void yyerror(const char* msg) {
        printf("%s\n",msg);
}
int main() {
    return yyparse();
}