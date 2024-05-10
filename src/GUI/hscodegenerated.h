#ifndef HSCODEGENERATED_H
#define HSCODEGENERATED_H

/*
 * 用于生成用来保存或另存为的代码。
 * 从textSepearted读入bodies和expressions
 * 从
 *
 * 似乎很难以写，先搁置。
 */

#include <QString>

class HsCodeGenerated
{
private:
    QString code;
    HsCodeGenerated(){}
public:
    static HsCodeGenerated& GetInstance();
    void Generate();
};

#endif // HSCODEGENERATED_H
