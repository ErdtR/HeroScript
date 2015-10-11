#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lexicalanalyzer.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString program = ui->textEdit->toPlainText();
    qDebug()<<program;
    LexicalAnalyzer analyzer;
    QList<Token> result = analyzer.parse(program);
    qDebug() << result.length();
    foreach (Token token, result) {
        qDebug() << token.getData()<<" --- "<<token.getType();
    }
}
