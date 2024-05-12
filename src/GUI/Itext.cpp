#include "Itext.h"
#include <QVBoxLayout>
#include "mainwindow.h"

MainWindow* mainwindow;

#include "textreaded.h"
// 按照文件名称读入文本
// 1F1R
void TReadFile(const QString &fileName){
    TextReaded::GetInstance().ReadText(fileName);
}


#include "textseperated.h"
// 分割原始文本
// 1F1R
void TSepr(){
    TextSeperated::GetInstance().Seperate();
}
QString TGetHead(){
    return TextSeperated::GetInstance().head;
}


#include "hsexprcalculator.h"
// 初始化编译器，生成变量表
// 1F1R
void TCInit(){
    HsExprCalculator::GetInstance().Initialize();
}
// 调用编译器，按照现有变量表进行计算
// 1FnR
void TCCalc(){
    HsExprCalculator::GetInstance().Calculate();
}


#include "hsexprcomponents.h"
// 清除变量表、函数表
// 1F1R
void TCCompClear(){
    HsExprComponents::GetInstance().Clear();
}
// 调用变量
// 1FnR
QVector<Variable>& TGetVars(){
    return HsExprComponents::GetInstance().Variables;
}


#include "textgenerated.h"
// 生成文本
// 1FnR
void TGenr(){
    TextGenerated::GetInstance().Generate();
}
// 获得生成的文本
// 1FnR
QString TGetGenr(){
    return TextGenerated::GetInstance().content;
}


#include "hscodegenerated.h"
// 生成保存的代码
// 1F1R
void TCodeGenr(){
    HsCodeGenerated::GetInstance().Generate();
}
// 获得生成的代码
// 1F1R
QString TCodeGetGenr(){
    return HsCodeGenerated::GetInstance().code;
}

// In Itext-Window::
// 链接主窗口
// 1F0R
void TWSetMainWindow(MainWindow *mw){
    mainwindow=mw;
}
void TWDispHead(QTextBrowser *Browser){
    Browser->setText(TGetHead());
    hsdebug<< "head displayed.";
}
// 在指定组件中展示生成的文本
// 1FnR
void TWDispText(QTextBrowser *Browser = nullptr){
    Browser->setText(TGetGenr());
    hsdebug<< "text displayed.";
    // 在Browser中显示拼接后的文本
}
#include "hsvareditwidget.h"
// 在指定组件中展示变量表，由于需要“特定组件”，所以需要获取MainWindow的友元权限。
// 同时，也负责连接变量表组件的信号与生成文本展示组件的槽函数。
// 1F1R
void TWDispVars(QWidget *widget_Variable_Container){
    QVBoxLayout *layout_Variable_Container = new QVBoxLayout;
    for(int index=0; index<TGetVars().size(); index++){
        // 对于每一个变量“名-值”对：
        if(TGetVars()[index].Name!=""){
            // 若变量名不为空：
            // 新建一个变量组件
            HsVarEditWidget *VarEditor = new HsVarEditWidget(
                index, widget_Variable_Container
                );
            // 连接信号：
            QObject::connect(VarEditor,&HsVarEditWidget::valueEdited,mainwindow,&MainWindow::on_action_value_edited);
            // 将变量组件添加到变量组件布局中：
            layout_Variable_Container->addWidget(VarEditor);
        }
    }
    widget_Variable_Container->setLayout(layout_Variable_Container);
}
// 清除变量展示组件中的变量表。
// 1F1R
void TWClearVarsDispWidget(QWidget *widget_Variable_Container) {
    QLayout* layout_Variable_Container = widget_Variable_Container->layout();
    if (layout_Variable_Container != nullptr) {
        // 删除布局中的所有组件
        QLayoutItem* item;
        while ((item = layout_Variable_Container->takeAt(0)) != nullptr) {
            if (item->widget()) {
                delete item->widget();  // 删除组件
            }
            delete item;  // 删除布局项
        }
    }
    delete layout_Variable_Container;
}



//Itext
// 清除全部旧数据，用在确认读入后，正式读入前。
// 1F1R
void TClearAll(){
    TextReaded::GetInstance().Clear();
    TextSeperated::GetInstance().Clear();
    HsExprComponents::GetInstance().Clear();
    TextGenerated::GetInstance().Clear();
    HsCodeGenerated::GetInstance().Clear();
    //TWClearVarsDispWidget();这个得手动调用，因为需要输入。
}
// 初始化全部，用在读入后、调用变量前。
// 1F1R
void TInitAll(){
    TSepr();
    TCCompClear();
    TCInit();
}
// 计算并生成全部，用在改变变量后、调用生成文本前。
void TCalcAll(){
    TCCalc();
    TGenr();
}

