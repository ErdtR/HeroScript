#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H
#include <QList>
#include <token.h>
#include <QRegExp>

class LexicalAnalyzer
{
public:
    LexicalAnalyzer();
    QList<Token> parse(QString program);
private:
    QList<Token> tokens;

    QList<Token> parseCommentsAndString(QList<Token> tokens);
    QList<Token> deleteWhiteSpaces(QList<Token> tokens);
};

#endif // LEXICALANALYZER_H
