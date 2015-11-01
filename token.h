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
    logicEqual,
    logicLess,
    logicMore,
    logicNotEqual,
    assigment,
    plus,
    minus,
    division,
    multiplication,
    var,
    event,
    ifToken,
    elseToken,
    whileToken,
    heroObject,
    goMethod,
    turnLeftMethod,
    turnRightMethod,
    collectGemMethod,
    sayMethod,
    stopedEvent,
    gemCollectedEvent,
    variable,
    unparsed
};

class Token
{
public:
    Token();
    Token(QString data, TokenType type);

    QString getData();
    TokenType getType();
    QString getTypeString();

private:
    QString _data;
    TokenType _type;
};

#endif // TOKEN_H
