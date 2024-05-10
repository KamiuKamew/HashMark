#ifndef HSVAREDITWIDGET_H
#define HSVAREDITWIDGET_H

/*
 * 专用于显示变量的组件类。
 * 从hsexprcomponents读入Variables
 * 向Itext-window提供含参构造函数。
 * 向Itext-window提供信号valueEdited。
 */

#include <QObject>
#include <QWidget>
#include <QLineEdit>

class HsVarEditWidget : public QWidget
{
    Q_OBJECT
private:
    qsizetype index;
    QLineEdit *nameLineEdit;
    QLineEdit *valueLineEdit;

public:
    HsVarEditWidget();
    HsVarEditWidget(qsizetype variableIndex, QWidget* parent);

private slots:
    void valueChanged(const QString &newValue);

signals:
    // 自定义的信号函数。
    // 信号去往MainWindow的on_action_value_edited，当变量被改变时刷新textBrowser_Main。
    // 信号连接自Itext的TWDispVars，在VarEditComponents被生成的时候便进行连接。
    void valueEdited();
};

#endif // HSVAREDITWIDGET_H
