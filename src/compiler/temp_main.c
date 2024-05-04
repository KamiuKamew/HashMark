#include <stdio.h>
#include "Interface.h"

/*
    注；
    这里的main函数只是用来临时测试的
    后面main函数会换到Qt中。
*/


int main() {
    // if (yyparse() == 0) { // Parse complete
    //     size_t length;
    //     const char **results = getExpressionResults(&length);
    //     for (size_t i = 0; i < length; ++i) {
    //         printf("%s\n", results[i]);  // Print all results
    //     }
    //     clearExpressionResults();
    // }
    // return 0;

    char ipt[100];
    while(1){
        scanf("%s",ipt);
        Comp_evalExprs(ipt);
        size_t length;
        const char **results = Comp_getExprnResults(&length);
        for (size_t i = 0; i < length; ++i) {
            printf("%s\n", results[i]);  // Print all results
        }
        Comp_clearExprResults();
    }
}
