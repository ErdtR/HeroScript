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

QString Token::getTypeString()
{
    switch(this->_type)
    {
    case comment: return "comment";
    case string: return "string";
    case number: return "number";
    case semicolon: return "semicolon";
    case leftParenthesis: return "leftParenthesis";
    case rightParenthesis: return "rightParenthesis";
    case leftCurlyBrace: return "leftCurlyBrace";
    case rightCurlyBrace: return "rightCurlyBrace";
    case dot: return "dot";
    case logicEqual: return "logicEqual";
    case logicLess: return "logicLess";
    case logicMore: return "logicMore";
    case logicNotEqual: return "logicNotEqual";
    case assigment: return "assigment";
    case plus: return "plus";
    case minus: return "minus";
    case division: return "division";
    case multiplication: return "multiplication";
    case var: return "var";
    case event: return "event";
    case ifToken: return "ifToken";
    case elseToken: return "elseToken";
    case whileToken: return "whileToken";
    case heroObject: return "heroObject";
    case goMethod: return "goMethod";
    case turnLeftMethod: return "turnLeftMethod";
    case turnRightMethod: return "turnRightMethod";
    case collectGemMethod: return "collectGemMethod";
    case sayMethod: return "sayMethod";
    case stopedEvent: return "stopedEvent";
    case gemCollectedEvent: return "gemCollectedEvent";
    case unparsed: return "unparsed";
    }
}

