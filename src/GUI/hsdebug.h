#ifndef HSDEBUG_H
#define HSDEBUG_H

/*
 * 只是一个
 *  平平无奇的
 *  全局的
 *  方便的
 *  调试用的
 * 宏定义罢了
 *
 * <乐>
 */

#include <QDebug>

// 设置区：
// 详细Debug信息：
#define hsDetailDebug 1
#define hsCalcDebug 0
#define hsSeprDebug 1

#include <QTextStream>
extern QTextStream null_stream;

#define hsdebug qDebug()<<__FILE__<<':'<<__LINE__<<'-'

#if hsDetailDebug
#define HSDebug qDebug()<<__FILE__<<':'<<__LINE__<<'-'
#else
#define HSDebug null_stream
#endif

#define HSDEBUG(BOOL) if(BOOL) qDebug()<<__FILE__<<':'<<__LINE__<<'-'

#endif // HSDEBUG_H
