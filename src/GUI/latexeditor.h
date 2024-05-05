#ifndef LATEXEDITOR_H
#define LATEXEDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QTextBrowser>
#include <QHBoxLayout>
#include <QSplitter>
#include <QProcess>
#include <QDir>
#include <QByteArray>

class LatexEditor : public QWidget {
    Q_OBJECT
public:
    LatexEditor(QWidget *parent = nullptr);

private:
    void setupUI();
    void updatePreview();
    QString latexToHtml(const QString& latexContent);

    QTextEdit *textEdit;
    QTextBrowser *textBrowser;
};

#endif // LATEXEDITOR_H
