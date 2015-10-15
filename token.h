#ifndef TOKEN_H
#define TOKEN_H
#include <QString>

enum TokenType{
    comment,
    string,
    number,
    semicolon,
    leftParenthesis,
    rightParenthesis,
    leftCurlyBrace,
    rightCurlyBrace,
    dot,
    unparsed
};

class Token
{
public:
    Token();
    Token(QString data, TokenType type);

    QString getData();
    TokenType getType();

private:
    QString _data;
    TokenType _type;
};

#endif // TOKEN_H
