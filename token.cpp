#include "token.h"

Token::Token()
{

}

Token::Token(QString data, TokenType type):_data(data), _type(type)
{

}

QString Token::getData()
{
    return _data;
}

TokenType Token::getType()
{
    return _type;
}

