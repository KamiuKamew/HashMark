#ifndef TEXTOPERATOR_H
#define TEXTOPERATOR_H

#include <QObject>
#include <QString>



class SeperatedText{
    Q_OBJECT
private:
    QString head;
    QVector<QString> bodies;
    QVector<QString> expressions;
    SeperatedText(){}
public:
    static SeperatedText& GetInstance();
    void Seperate();
};

#endif // TEXTOPERATOR_H
