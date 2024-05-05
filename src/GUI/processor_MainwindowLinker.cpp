#include "processors.h"

#include <QVBoxLayout>
#include "widget_VariableEditor.h"

QString Processors::joinFileBody() {
    QString outputText;
    for(int index=0; index<fileBody.size(); index++){
        outputText+=fileBody[index];
        if(!fileExpressions[index].isEmpty())
            outputText+=evaluateExpression(fileExpressions[index], Variables, Functions);
    }
    return outputText;
}

void Processors::displayTextInBrowser(QTextBrowser *textBrowser_input = nullptr) {
    if(textBrowser==nullptr) textBrowser=textBrowser_input;
    textBrowser->setText(joinFileBody()); // 在textBrowser中显示拼接后的文本
}

void Processors::displayVariableInWidget(QWidget *widget_Variable_Container){
    // 新建竖直布局，用于存放每一对变量名-变量值
    QVBoxLayout *layout_Variable_Container = new QVBoxLayout;
    for(int variable_index=0; variable_index<Variables.size(); variable_index++){
        // 对于每一个变量“名-值”对：
        if(Variables[variable_index].Name!=""){
            // 若变量名不为空：
            // 新建一个变量组件
            Widget_Variable *widget_Variable_Editor = new Widget_Variable(
                Variables[variable_index].Name, Variables[variable_index].Value, widget_Variable_Container
                );
            // 连接信号：
            connect(widget_Variable_Editor,&Widget_Variable::valueEdited,this,&Processors::on_action_variableEditor_valueEdited);
            // 将变量组件添加到变量组件布局中：
            layout_Variable_Container->addWidget(widget_Variable_Editor);
        }
    }
    widget_Variable_Container->setLayout(layout_Variable_Container);
}

void Processors::on_action_variableEditor_valueEdited(){
    displayTextInBrowser();
}
