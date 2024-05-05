// #ifndef WIDGETVARIABLE_H
// #define WIDGETVARIABLE_H

// #include <QHBoxLayout>
// #include <QLineEdit>
// #include <QString>

// class Widget_Variable : public QWidget {
//     Q_OBJECT

// private:
//     QString &m_variableValue;
//     QLineEdit *nameLineEdit;
//     QLineEdit *valueLineEdit;

// public:
//     Widget_Variable(const QString &variableName, QString &variableValue, QWidget *parent = nullptr);

// private slots:
//     void valueChanged(const QString &newValue);

// signals:
//     void valueEdited();
// };

// #endif // WIDGETVARIABLE_H


#include "widget_VariableEditor.h"

Widget_Variable::Widget_Variable(const QString &variableName, QString &variableValue, QWidget *parent):
    QWidget(parent),
    m_variableValue(variableValue)
{
    // 创建垂直布局并设置给Widget_Variable
    QHBoxLayout *layout = new QHBoxLayout(this);

    // 创建一个不可编辑的LineEdit，用于展示VariableName
    nameLineEdit = new QLineEdit(variableName);
    nameLineEdit->setReadOnly(true);
    layout->addWidget(nameLineEdit);

    // 创建一个可编辑的LineEdit，用于用户更改VariableValue
    valueLineEdit = new QLineEdit(variableValue);
    layout->addWidget(valueLineEdit);

    // 连接信号
    connect(valueLineEdit, &QLineEdit::textChanged, this, &Widget_Variable::valueChanged);
}

void Widget_Variable::valueChanged(const QString &newValue) {
    m_variableValue = newValue;
    emit valueEdited(); // 发射信号，表示变量值已编辑
}
