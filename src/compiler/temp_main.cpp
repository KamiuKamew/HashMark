#include "compiler.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

/*
    注；
    这里的main函数只是用来临时测试�?
    后面main函数会换到Qt中�?
*/

// if (yyparse() == 0) { // Parse complete
    //     size_t length;
    //     const char **results = getExpressionResults(&length);
    //     for (size_t i = 0; i < length; ++i) {
    //         printf("%s\n", results[i]);  // Print all results
    //     }
    //     clearExpressionResults();
    // }
    // return 0;

int main() {
    char ipt[100];
    while(1){
        cin>>ipt;
        if(!strcmp(ipt,"clv")){
            Comp_clearVars();
            continue;
        }
        if(!strcmp(ipt,"adv")){
            char name[100];
            int value;
            cin>>name>>value;
            Comp_addVar(name,value);
            continue;
        }
        if(!strcmp(ipt,"gtv")){
            cout<<"tot vars have "<<Comp_getNumVar()<<'\n';
            int index;
            cin>>index;
            char* name;
            double value=Comp_getVar(index, &name);
            cout<<name<<": "<<value<<'\n';
            continue;
        }
        Comp_evalExprs(ipt);
        size_t length;
        const char **results = Comp_getExprnResults(&length);
        for (size_t i = 0; i < length; ++i) {
            cout<<results[i]<<endl;  // Print all results
        }
        Comp_clearExprResults();
    }
}
