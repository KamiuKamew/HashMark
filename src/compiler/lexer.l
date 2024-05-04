%{
#include "y.tab.h"
#include "var.h"
#include <string.h>
%}

%%
[0-9]+                  { yylval.dval = atof(yytext);     return NUMBER;  }

([0-9]*\.[0-9]+)        { yylval.dval = atof(yytext);     return NUMBER;  }

[ \t] ;

[A-Za-z][A-Za-z0-9]*    { yylval.varname = strdup(yytext);  return NAME; }

"$"                     { return 0; }

\n|.                    {  return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}