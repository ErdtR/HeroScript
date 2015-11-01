#ifndef PARSER_H
#define PARSER_H
#include <QList>
#include "simplecommand.h"
#include "conditioncommand.h"
#include "expression.h"
#include "token.h"
#include "context.h"

class Parser
{
private:
    Context *_context;
    VarCommand *parseVarCommand(QList<Token> tokens, int start, int end);
    AssigmentCommand *parseAssigmentCommand(QList<Token> tokens, int start, int end);
    Command *parseHeroCommand(QList<Token> tokens, int start, int end);
    Expression *parseExp(QList<Token> tokens, int start, int end);
    WhileCommand *parseWhileCommand(QList<Token> tokens, int start);
    IfCommand *parseIfCommand(QList<Token> tokens, int start);
    int indexOf(QList<Token> tokens, int start, TokenType type);
    int indexOfPair(QList<Token> tokens, int start, TokenType left, TokenType right);
public:
    Parser(Context *context);
    Command *parse(QList<Token> tokens, int start, int end);
};

#endif // PARSER_H
