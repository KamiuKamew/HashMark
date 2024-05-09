#include "textseperated.h"
#include "textreaded.h"
#include "hsdebug.h"

TextSeperated& TextSeperated::GetInstance(){
    static TextSeperated instance;
    return instance;
}

void TextSeperated::Seperate(){
    // 获取Text类的单例和其内容
    TextReaded& text = TextReaded::GetInstance();
    QString content = text.content;

    int dbHashStart = content.indexOf("##");
    int dbHashEnd = 0;
    int dbHashEnd_last = -2;

    while (dbHashStart != -1) {
        dbHashEnd = content.indexOf("##", dbHashStart + 2);
        if (dbHashEnd != -1) {
            // 从上一个双井号后到当前双井号前的文本
            QString BodyPiece = content.mid(dbHashEnd_last + 2, dbHashStart - (dbHashEnd_last + 2));
            // 双井号间的表达式
            QString Expression = content.mid(dbHashStart + 2, dbHashEnd - (dbHashStart + 2));

            bodies.append(BodyPiece);
            expressions.append(Expression);

            // 更新上一个双井号结束位置，以便下次循环使用
            dbHashEnd_last = dbHashEnd;
            dbHashStart = content.indexOf("##", dbHashEnd + 2);
        } else {

            //REMINDER: 这里写一个提示井号表达式不全的窗口，替换掉这个qdebug。

            qDebug() << "Incomplete hash sign expression";
            break;
        }
    }

    // 添加最后一个表达式后的文本
    QString lastPiece = content.mid(dbHashEnd_last + 2);
    bodies.append(lastPiece);
    expressions.append("");  // 没有表达式与之对应
    sepnum=bodies.size();

    hsdebug<<"file separatded. sepnum = "<<sepnum;
}
