#include "latexeditor.h"


LatexEditor::LatexEditor(QWidget *parent) : QWidget(parent) {
    setupUI();
    connect(textEdit, &QTextEdit::textChanged, this, &LatexEditor::updatePreview);
}

void LatexEditor::setupUI() {
    textEdit = new QTextEdit;
    textBrowser = new QTextBrowser;
    textBrowser->setOpenExternalLinks(true);

    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(textEdit);
    splitter->addWidget(textBrowser);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(splitter);

    setLayout(layout);
}

void LatexEditor::updatePreview() {
    QString latexContent = textEdit->toPlainText();
    textBrowser->setHtml(latexToHtml(latexContent));
}

QString LatexEditor::latexToHtml(const QString& latexContent) {
    // Call Python script to convert LaTeX to HTML
    QProcess process;
    QString scriptPath = QDir::currentPath() + "/latex_to_html.py"; // 获取 Python 脚本的路径
    process.start("python", QStringList() << scriptPath << latexContent); // 将 LaTeX 内容作为参数传递给 Python 脚本
    process.waitForFinished(-1);
    QByteArray output = process.readAllStandardOutput();
    QString htmlContent(output);

    return htmlContent;
}
