#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lexicalanalyzer.h"
#include "context.h"
#include "parser.h"
#include "command.h"
#include "interpreter.h"
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
    int length = result.length();
    ui->tableWidget->setRowCount(length);
    int i = 0;
    foreach (Token token, result) {
        QTableWidgetItem *tokenString = new QTableWidgetItem(token.getData());
        QTableWidgetItem *tokenTypeString = new QTableWidgetItem(token.getTypeString());
        //qDebug() << token.getData()<<" --- "<<token.getType();
        ui->tableWidget->setItem(i, 0, tokenString);
        ui->tableWidget->setItem(i, 1, tokenTypeString);
        i++;
    }
    Context context;
    Parser parser = Parser(&context);
    Command *command = parser.parse(result, 0);
    Interpreter interpreter;
    interpreter.interpret(command);
}
