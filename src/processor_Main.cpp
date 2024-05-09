// // Main：
// private:
//      QObject *parent;
//      QTextBrowser *textBrowser;
// public:
//      Processors(QObject *parent_input);
//      ~Processors(); // 析构函数
// private slots:
//      void on_action_variableEditor_valueEdited();


#include "processors.h"


Processors::Processors(QObject *parent_input):
    parent(parent_input),
    textBrowser(nullptr){}

Processors::~Processors() {} // 析构函数空实现
