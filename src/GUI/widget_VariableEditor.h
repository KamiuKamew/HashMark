#ifndef WIDGET_VARIABLEEDITOR_H
#define WIDGET_VARIABLEEDITOR_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QString>

class Widget_Variable : public QWidget {
    Q_OBJECT

private:
    QString &m_variableValue;
    QLineEdit *nameLineEdit;
    QLineEdit *valueLineEdit;

public:
    Widget_Variable(const QString &variableName, QString &variableValue, QWidget *parent = nullptr);

private slots:
    void valueChanged(const QString &newValue);

signals:
    void valueEdited();
};

#endif // WIDGET_VARIABLEEDITOR_H
