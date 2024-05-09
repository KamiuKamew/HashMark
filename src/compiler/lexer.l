%{
#include "y.tab.h"
#include "var.h"
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void evaluateExpressions(const char* expressions);
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

void evaluateExpressions(const char* expressions) {
    char tempFilename[MAX_PATH];
    tmpnam(tempFilename);
    FILE* tempFile = fopen(tempFilename, "w+");
    if (!tempFile) {
        perror("Failed to open temporary file");
        return;
    }
    fputs(expressions, tempFile);
    fflush(tempFile);
    rewind(tempFile);
    yyin = tempFile;
    yyparse();
    yyin = stdin;
    fclose(tempFile);
    remove(tempFilename);
}
