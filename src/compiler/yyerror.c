#include "yyerror.h"
#include <stdio.h>
void yyerror(const char* msg) {
        printf("%s\n",msg);
}