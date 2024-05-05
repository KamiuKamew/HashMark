#ifndef PROCESSORS_H
#define PROCESSORS_H

#include <QObject>
#include <QTextBrowser>
#include <QString>
#include <QVector>
#include <QMap>
#include <QDebug>


class Processors :public QObject{
    Q_OBJECT

    /*
     * DONE:
     *      Main
     *      FileSeparator
     *
     * WAITING TO BE TESTED:
     *      ExpressionCalculator
     *
     * DEALING:
     *      MainwindowLinker
     *
     * WAITING TO BE WROTE:
     *      FunctionCalculator
     *      HashBlockProcessor
     */


// Main：

public:
    Processors(QObject *parent_input);
    ~Processors(); // 析构函数


// MainwindowLinker:

private:
    QObject *parent;
    QTextBrowser *textBrowser;
public:
    QString joinFileBody(); // 拼接fileBody中的文本
    void displayTextInBrowser(QTextBrowser *textBrowser); // 在textBrowser中显示拼接后的文本
    void displayVariableInWidget(QWidget *rootWidget);
private slots:
    void on_action_variableEditor_valueEdited();


// FileSeparator:

public: struct FunctionDefinition {
        QString Name; // 函数名
        QList<QString> arguments; // 参数列表
        QString expression; // 表达式

        FunctionDefinition(QString n, QList<QString> a, QString e):
            Name(n),
            arguments(a),
            expression(e){
            qDebug() << "function created: "+n;
        }
        // 输出函数定义信息
        void print() const {
            qDebug() << "Function Name:" << Name;
            qDebug() << "Arguments:";
            for (const QString& arg : arguments) {
                qDebug() << arg;
            }
            qDebug() << "Expression:" << expression;
        }
    };
public: struct VariableDefinition {
        QString Name;
        QString Value;

        VariableDefinition(QString n, QString v):
            Name(n),
            Value(v){
            qDebug() << "variable created: "<<n<<"with walue"<<v;
        }
        friend bool operator==(VariableDefinition v1, const QString qs){
            return v1.Name == qs;
        }
    };

private:
    QString fileHead; // 文件头
    QVector<QString> fileBody; // 文件主体
    QVector<QString> fileExpressions; // 文件表达式
    QVector<QString> fileVariableName; // 文件变量名
    QVector<QString> fileVariableValue; // 文件变量值
    QVector<VariableDefinition> Variables; // 变量（名-值）
    QVector<FunctionDefinition> Functions; // 函数（名-值列表-表达式）
public:
    Processors(QObject *parent_input, const QString &fileName); // 构造函数，接受文件名作为参数
    void fileSeparate(const QString &fileName);


// ExpressionCalculator:

private:
    QString getValue(QString &Name, QVector<Processors::VariableDefinition> &localVariables, bool &isNameValid);
    void createNewVariable(QString &variableName, QString &variableValue);
    void createNewFunction(QString &functionName, QList<QString> &functionArguments, QString &functionExpression);

    QString evaluateExpression(const QString& expression, QVector<VariableDefinition>& variables, QVector<FunctionDefinition>& functions);


};

#endif // PROCESSORS_H
