#ifndef HSCODEGENERATED_H
#define HSCODEGENERATED_H

/*
 * 用于生成用来保存或另存为的代码。
 * 从textSepearted读入head，bodies和expressions
 * 从hsexprcomponents读入variables。
 * 向Itext开放code；
 */

#include <QString>

class HsCodeGenerated
{
    friend QString TCodeGetGenr();
private:
    QString code;
    HsCodeGenerated(){}
public:
    static HsCodeGenerated& GetInstance();
    void Clear();
    void Generate();
};

#endif // HSCODEGENERATED_H
