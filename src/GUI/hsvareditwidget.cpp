#include "hsvareditwidget.h"
#include "hsexprcomponents.h"
#include <QHBoxLayout>

qsizetype index=0;

HsVarEditWidget::HsVarEditWidget() {}

HsVarEditWidget::HsVarEditWidget(qsizetype variableIndex, QWidget* parent):
    QWidget(parent)
{
    index=variableIndex;
    QVector<Variable>& vars = HsExprComponents::GetInstance().Variables;
    // 创建垂直布局并设置给Widget_Variable
    QHBoxLayout *layout = new QHBoxLayout(this);

    // 创建一个不可编辑的LineEdit，用于展示VariableName
    nameLineEdit = new QLineEdit(vars[variableIndex].Name);
    nameLineEdit->setReadOnly(true);
    layout->addWidget(nameLineEdit);

    // 创建一个可编辑的LineEdit，用于用户更改VariableValue
    valueLineEdit = new QLineEdit(vars[variableIndex].Value);
    layout->addWidget(valueLineEdit);

    // 连接信号
    connect(valueLineEdit, &QLineEdit::textChanged, this, &HsVarEditWidget::valueChanged);
}

void HsVarEditWidget::valueChanged(const QString &newValue) {
    QVector<Variable>& vars = HsExprComponents::GetInstance().Variables;
    vars[index].Value = newValue;
    HSDebug<<"value"<<nameLineEdit->text()<<"changed into"<<valueLineEdit->text();
    HSDebug<<"vars[0] is"<<vars[0].Value;
    emit valueEdited(); // 发射信号，表示变量值已编辑
}
