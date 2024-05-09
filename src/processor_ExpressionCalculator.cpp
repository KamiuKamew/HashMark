#include "processors.h"

#include <QCoreApplication>
#include <QString>
#include <QMap>
#include <QDebug>
#include <QStack>
#include <QMessageBox>
#include <QRegularExpression>

// 一些小组件函数
int precedence(QChar op);
QString performOperation(QString& val1, QString& val2, QChar op);
QString Processors::getValue(QString &Name, QVector<Processors::VariableDefinition> &localVariables, bool &isNameValid){
    isNameValid = true;

    // 如果是个数：（int或者float）（注：如果是float那么一定是int）
    if([](const QString &str) -> bool {
            bool isNumber;
            str.toFloat(&isNumber);
            return isNumber;
        }(Name)){
        return Name;
    }

    // 如果是个变量：
    else{
        // 如果变量名为空：
        if (Name.isEmpty()) {
            // 则变量名无效，返回空字符串
            isNameValid = false;
            return QString();
        }
        // 如果没有在局部参数列表中定义该变量：
        if (!localVariables.contains(Name)){
            // 则在总参数列表中生成一个变量并继续（事实上马上就会退出）。
            Variables.push_back(VariableDefinition(Name,""));
        }
        // 查找临时字符串在变量列表中的值
        for(VariableDefinition &variable:localVariables) if(variable.Name == Name) return variable.Value;
    }

    qWarning()<<"ERROR: unkown mistake (in function getValue)";
    isNameValid = false;
    return "";
}


// 表达式计算函数（表达式，全局参数键值对表，全局函数表）
QString Processors::evaluateExpression(const QString& expression, QVector<VariableDefinition>& localVariables, QVector<FunctionDefinition>& localFunctions) {

    qDebug()<<"expression: "<<expression;

    int index_DefineSymbol = expression.indexOf(":=");
    if(index_DefineSymbol == -1){
        QString tempString; // 临时字符串，用于存储变量名或数字
        QStack<QString> valueStack; // 值栈，存储操作数
        QStack<QChar> operatorStack; // 操作符栈，存储操作符
        // 遍历表达式中的每个字符
        for (int i = 0; i < expression.length(); ++i) {
            QChar ch = expression.at(i);
        // 1.变量名处理模块
            if (ch.isDigit() || ch.isLetter()) {
                // 如果字符是数字或字母，则将其添加到临时字符串中
                tempString.append(ch);
            }
        // 2.操作符处理模块
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
                // 如果字符是操作符，则处理前面的临时字符串
                bool isTempStringValid;
                QString tempValue = getValue(tempString, localVariables, isTempStringValid);
                if(isTempStringValid){
                    // 将变量值压入值栈中，并清空临时字符串
                    valueStack.push(tempValue);
                    tempString.clear();
                }
                else{
                    qDebug()<<"uncountable expression"<<expression;
                    return "";
                }
                // 执行运算
                while (!operatorStack.isEmpty() && precedence(operatorStack.top()) >= precedence(ch)) {
                    QString val2 = valueStack.pop();
                    QString val1 = valueStack.pop();
                    QChar op = operatorStack.pop();
                    QString result = performOperation(val1, val2, op);
                    valueStack.push(result);
                }
                // 将当前操作符压入操作符栈中
                operatorStack.push(ch);
            }
        // 3.函数调用处理模块
            else if (ch == '(') {

                // 如果字符是左括号，则处理函数调用
// REMINDER: 不一定是函数调用。这里写一个优先级括号处理.
                int endIndex = expression.indexOf(")", i);
                if (endIndex == -1) {
                    qWarning() << "Error: Invalid expression!";
                    return QString();
                }

                // 提取函数名
                QString functionName = tempString.trimmed();
                tempString.clear();
                // 注：这里tempstring会在函数计算完毕后替换为函数返回值，不然等一下操作符运算的时候就空运算了。

                // 提取参数值表达式列表：
                QList<QString> argumentValueExpressions;
                for (const QString& arg :
                     expression.mid(i + 1, endIndex - i - 1).trimmed()
                         .split(",", Qt::SkipEmptyParts)) {
                    argumentValueExpressions.append(arg.trimmed());
                }

                // 在已定义的函数列表中查找函数
                bool foundFunction = false;
                for (const FunctionDefinition& func : localFunctions) {
                    if (func.Name == functionName && func.arguments.count() == argumentValueExpressions.count()) {
                        foundFunction = true;

                        // 下面的代码模拟了传参的过程：
                        // 新建函数的变量键值对，并把当前局部（这个函数外的）变量键值对传进去。
                        QVector<VariableDefinition> functionVariables = localVariables;
                        // 将【从参数值表达式中计算得到的参数值】设置到变量键值对中：
                        for (int j = 0; j < argumentValueExpressions.count(); ++j)
                            // 在函数的变量键值对列表中……
                            functionVariables.push_back(
                                // 新建变量键值对……
                                VariableDefinition(
                                    // 键：变量名：第i个参数
                                    func.arguments.at(j),
                                    // 值：变量值：在当前局部变量环境计算参数值表达式的值
                                    evaluateExpression(argumentValueExpressions.at(j), localVariables, localFunctions)
                                    )
                                );

                        // 然后就可以计算函数值了：
                        // 在函数的参数环境、全局的函数环境中，计算函数表达式的值，并赋值给临时字符串
                        qDebug()<<"evaluate function expression: "
                                 <<"    function name:"<<func.Name
                                 <<"    function variables:"<<functionVariables[0].Name<<functionVariables[0].Value<<functionVariables[1].Name<<functionVariables[1].Value
                                 <<"    function expression:"<<func.expression;
                        tempString = evaluateExpression(func.expression, functionVariables, localFunctions);
                        break;
                    }
                }

                // 处理没有找到函数的情况：
                if (!foundFunction) {
                    qWarning() << "Error: Function" << functionName << "not found or arguments mismatch!";
                    return QString();
                }

                i = endIndex; // 更新索引
            }
        }

        // 处理剩余的临时字符串
        if (!tempString.isEmpty()) {
// 这里的处理逻辑照搬上面的字符串处理逻辑：
            bool isTempStringValid;
            QString tempValue = getValue(tempString, localVariables, isTempStringValid);
            if(isTempStringValid){
                valueStack.push(tempValue);
                tempString.clear();
            }
// 照搬完毕.

        // 执行剩余的运算
            while (!operatorStack.isEmpty()) {
                QString val2 = valueStack.pop();
                QString val1 = valueStack.pop();
                QChar op = operatorStack.pop();
                QString result = performOperation(val1, val2, op);
                valueStack.push(result);
            }

            // 返回最终结果
            return valueStack.pop();
        }
        else{
            qWarning()<<"ERROR: unkown mistake (in function evaluateExpression:if(index_DefineSymbol == -1)) in expression:"<<expression;
            return "";
        }
    }
    else{
        QString Name=expression.first(index_DefineSymbol);
        QString Value=expression.mid(index_DefineSymbol+2);

        if(Name.endsWith(')')){
            int startIndex=Name.indexOf('(');

            if(startIndex==-1){
                qWarning() << "Error: Invalid expression! (Function definition error)";
                return QString();
            }

            QString functionName=Name.first(startIndex);
            // 如果已定义该函数：
// REMINDER:这里有奇怪bug。检测不到已有的函数。
            for(FunctionDefinition &function:Functions) if(function.Name == functionName){
                    // 不进行同名函数重载，也不打印。
                    return "";
                }
            // 如果没定义该函数：
            QList<QString> functionArguments;
            for (const QString& arg :
                 Name.mid(startIndex+1, Name.length()-(startIndex+1)-1).trimmed()
                     .split(",", Qt::SkipEmptyParts)) {
                functionArguments.append(arg.trimmed());
            }
            QString functionExpression=Value;

            Functions.append(FunctionDefinition(
                functionName,functionArguments,functionExpression));
        }
        else{
            // 定义新的赋初值的变量.
            // 如果已定义该变量：
            for(VariableDefinition &variable:Variables) if(variable.Name == Name){
                // 不进行重复定义，只打印。
                    return variable.Value;
            }
            // 如果没定义该变量：
            Variables.push_back(VariableDefinition(Name,Value));
            return Value;
        }
    }
    // test:
    for(FunctionDefinition &f:Functions){
        f.print();
    }
    return "";
}

// 函数定义：获取操作符的优先级
int precedence(QChar op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; // 其他字符的优先级较低
}

// 函数定义：执行操作

QString performOperation(QString& val1, QString& val2, QChar op) {

// REMINDER:
// 待完善：写一个东西别让它一直弹窗口。最好放到最上面的窗口里显示。

    // 情况0：任何一个变量值为空变量（未定义）：
    if(val1.isEmpty() || val2.isEmpty()){
        // 这里有两种可能方法：将其视为空变量进行处理，或者将其视为未定义变量处理。

        // 1.空变量处理方法：
        qWarning()<< "void variable calculating";
        return "";

        // // 2.未定义变量处理方法：
        // return val1+val2;
    }

    if(val1.endsWith('.')) val1.remove(val1.length() - 1, 1);
    if(val2.endsWith('.')) val2.remove(val2.length() - 1, 1);

    bool isVal1Int, isVal2Int;
    bool isVal1Float, isVal2Float;
    int v1Int = val1.toInt(&isVal1Int);
    int v2Int = val2.toInt(&isVal2Int);
    float v1Float = val1.toFloat(&isVal1Float);
    float v2Float = val2.toFloat(&isVal2Float);

    // 情况1：两个数都是int：
    if(isVal1Int && isVal2Int){
        int resultInt = 0;
        switch (op.toLatin1()) {
        case '+':
            resultInt = v1Int + v2Int;
            break;
        case '-':
            resultInt = v1Int - v2Int;
            break;
        case '*':
            resultInt = v1Int * v2Int;
            break;
        case '/':
            if (v2Int != 0)
                resultInt = v1Int / v2Int;
            else{
                QMessageBox::warning(nullptr, "Error", "Division by zero");
                return "";
            }
            break;
        case '%':
            if (v2Int != 0)
                resultInt = v1Int % v2Int;
            else{
                QMessageBox::warning(nullptr, "Error", "Modulo by zero");
                return "";
            }
            break;
        case '^':
            resultInt = qPow(v1Int, v2Int);
            break;
        default:
            QMessageBox::warning(nullptr, "Error", "Invalid operator(1)");
            return ""; // 返回错误字符串
        }
        return QString::number(resultInt);
    }

    // 情况2：两个数都是float（提示：是int就一定是float）：
    else if(isVal1Float && isVal2Float){
        float resultFloat = 0;
        switch (op.toLatin1()) {
        case '+':
            resultFloat = v1Float + v2Float;
            break;
        case '-':
            resultFloat = v1Float - v2Float;
            break;
        case '*':
            resultFloat = v1Float * v2Float;
            break;
        case '/':
            if (v2Float != 0)
                resultFloat = v1Float / v2Float;
            else{
                QMessageBox::warning(nullptr, "Error", "Division by zero");
                return "";
            }
            break;
        case '%':
            QMessageBox::warning(nullptr, "Error", "Modulo with float");
            break;
        case '^':
            resultFloat = qPow(v1Float, v2Float);
            break;
        default:
            QMessageBox::warning(nullptr, "Error", "Invalid operator(2)");
            return ""; // 返回错误字符串
        }
        return QString::number(resultFloat);
    }

    // 情况3：至少有一个数连float也不是：
    else{
        // 两个字符串拼接
        if (op == '+')
            return val1 + val2;
        else {
            QMessageBox::warning(nullptr, "Error", "Invalid operation for non-numeric values");
            return ""; // 返回错误字符串
        }
    }
}
