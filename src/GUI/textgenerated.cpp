#include "textgenerated.h"
#include "textseperated.h"
#include "hsexprcalculator.h"
#include <QVector>
#include <QString>
#include "hsdebug.h"

TextGenerated& TextGenerated::GetInstance() {
    static TextGenerated instance;
    return instance;
}

void TextGenerated::Clear(){
    content.clear();
}

// 注：这里每次生成都是清空以前生成的文本后才再次生成。
void TextGenerated::Generate(){
    Clear();
    QVector<QString>& bodies = TextSeperated::GetInstance().bodies;
    QVector<QString>& exprResults = HsExprCalculator::GetInstance().expressionResults;
    qint32 genrnum = TextSeperated::GetInstance().sepnum;

    for(int index=0; index<genrnum; index++){
        content+=bodies[index];
        content+=exprResults[index];
    }
    hsdebug<<"target generated. size ="<<content.size();
}
