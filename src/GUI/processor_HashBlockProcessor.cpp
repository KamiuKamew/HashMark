// /*
// // HashBlockProcessor:

// private:struct FunctionDefinition {
//         QString functionName; // 函数名
//         QMap<QString, QString> arguments; // 参数列表
//         QString expression; // 表达式

//         // 输出函数定义信息
//         void print() const {
//             qDebug() << "Function Name:" << functionName;
//             qDebug() << "Arguments:";
//             for (auto it = arguments.constBegin(); it != arguments.constEnd(); ++it) {
//                 qDebug() << it.key();
//             }
//             qDebug() << "Expression:" << expression;
//         }
//     };
// private:
//     QMap<QString, QString> Variables;
//     QList<FunctionDefinition> Functions;
//     FunctionDefinition parseFunctionDefinition(const QString& definition);
// */

// #include "processors.h"

// // 函数定义解析函数
// Processors::FunctionDefinition  Processors::parseFunctionDefinition(const QString& definition) {
//     FunctionDefinition funcDef;
//     // 查找:=的位置
//     int index = definition.indexOf(":=");
//     if (index == -1) {
//         qWarning() << "Error: Invalid function definition!";
//         return funcDef;
//     }

//     // 提取函数名和参数列表
//     QString header = definition.left(index).trimmed();

//     // 检查格式是否正确
//     if (header.indexOf("(") == -1 || !header.endsWith(")")) {
//         // 若没有 前括号 ，或者不以 后括号 为结尾：
//         qWarning() << "Error: Invalid function definition!";
//         return funcDef;
//     }

//     // 提取函数名
//     int argStartIndex = header.indexOf("(");
//     funcDef.functionName = header.left(argStartIndex).trimmed();

//     // 提取参数列表
//     QString args = header.mid(argStartIndex + 1, index - argStartIndex - 1).trimmed();
//     funcDef.arguments = args.split(",", Qt::SkipEmptyParts);

//     // 提取表达式
//     funcDef.expression = definition.mid(index + 2).trimmed();

//     return funcDef;
// }
