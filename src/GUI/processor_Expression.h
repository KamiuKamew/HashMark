// #ifndef PROCESSOR_EXPRESSION_H
// #define PROCESSOR_EXPRESSION_H

// #include <QMap>
// #include <QString>
// #include <QVector>
// #include <QChar>
// using namespace std;

// class Processor_Expression{
//     /*
//      * 1.能识别一个新定义的变量；
//      * 2.能识别初始化符号“:=”；
//      * 3.能识别运算符号+ - * / ^ % ，%是取模，^是幂运算
//      * （注意：可以进行分数与负数次幂运算）；
//      * 4.能识别函数定义（格式为且仅为：<函数名>(<形式参数>):=<函数体>）；
//      * 5.能识别函数调用；
//      * 6.能支持字符串+运算。
//      */
// private:
//     QMap<QString,QString> variables;
//     QMap<QString,QString> functions;
//     const QVector<QChar> operators={'+','-','*','/','^','%'};

// public:
//     void processInputLine(const QString& inputLine){
//         // 1.寻找定义符号“:=”
//         int index_DefineSymbol = inputLine.indexOf(":=");
//         if(index_DefineSymbol == -1){
//             // 当不存在定义符号的时候（即：这是一个未赋值的新变量定义，或者是一个表达式。）：
//             // 2.寻找表达式关键字——运算符：

//             QString temp_VariableName;
//             for(int index=0; index<inputLine.length(); index++){
//                 // 依次观察每一个字符：
//                 if(operators.indexOf(inputLine[index]) == -1){
//                     // 若字符不是运算符：
//                     temp_VariableName+=inputLine[index];
//                 }
//                 else{
//                     // 若字符是运算符：

//                 }
//             }

//         }
//         else{
//             // 当存在定义福好多时候（即：这是一个赋初值的新变量定义，或者是一个新函数定义。）

//         }
//     }
// };



// #endif // PROCESSOR_EXPRESSION_H


