#ifndef TOKEN_H
#define TOKEN_H
#include <QString>

enum TokenType{
    comment,
    string,
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
