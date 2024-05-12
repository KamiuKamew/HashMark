#include "hscodegenerated.h"
#include "textseperated.h"
#include "hsexprcomponents.h"

HsCodeGenerated& HsCodeGenerated::GetInstance(){
    static HsCodeGenerated instance;
    return instance;
}

void HsCodeGenerated::Clear(){
    code.clear();
}

void HsCodeGenerated::Generate(){
    Clear();

    QString& head = TextSeperated::GetInstance().head;
    QVector<QString>& bodies = TextSeperated::GetInstance().bodies;
    QVector<QString>& expressions = TextSeperated::GetInstance().expressions;
    QVector<Variable>& Variables = HsExprComponents::GetInstance().Variables;

    code+=("#{"+head+"}#");
    for(qsizetype i=0; i<Variables.size(); i++){
        code+=("##"+Variables[i].Name+':'+Variables[i].Value+"##");
    }
    for(qsizetype i=0; i<bodies.size(); i++){
        code+=bodies[i];
        code+="##"+expressions[i]+"##";
    }
}
