#include "Itext.h"

#include "textreaded.h"
// 按照文件名称读入文本
void TReadFile(const QString &fileName){
    TextReaded::GetInstance().ReadText(fileName);
}


#include "textseperated.h"
// 分割原始文本
void TSepr(){
    TextSeperated::GetInstance().Seperate();
}


#include "hsexprcalculator.h"
// 初始化编译器，生成变量表
void TCInit(){
    HsExprCalculator::GetInstance().Initialize();
}
// 调用编译器，按照现有变量表进行计算
void TCCalc(){
    HsExprCalculator::GetInstance().Calculate();
}


#include "hsexprcomponents.h"
// 清除变量表、函数表
void TCCompClear(){
    HsExprComponents::GetInstance().ComponentsClear();
}
// 调用变量
QVector<Variable>& TGetVars(){
    return HsExprComponents::GetInstance().Variables;
}


#include "textgenerated.h"
// 生成文本
void TGenr(){
    TextGenerated::GetInstance().Generate();
}
// 获得生成的文本
QString TGetGenr(){
    return TextGenerated::GetInstance().content;
}


//Itext
// 初始化全部，用在读入后、调用变量前。
void TInitAll(){
    TSepr();
    TCCompClear();
    TCInit();
}
// 计算并生成全部，用在改变变量后、调用生成文本前。
void TCalcAll(){
    TCCalc();
    TGenr();
}
