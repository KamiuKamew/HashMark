#include "textgenerated.h"
#include "textseperated.h"
#include "hsexprcalculator.h"
#include <QVector>
#include <QString>

TextGenerated& TextGenerated::GetInstance() {
    static TextGenerated instance;
    return instance;
}

void TextGenerated::Generate(){
    QVector<QString>& bodies = TextSeperated::GetInstance().bodies;
    QVector<QString>& results = HsExprCalculator::GetInstance().results;
    qint32 genrnum = TextSeperated::GetInstance().sepnum;

    for(int index=0; index<genrnum; index++){
        content+=bodies[index];
        content+=results[index];
    }
}
