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
    Expression *parseExp(QList<Token> tokens, int start, int end);
    int indexOf(QList<Token> tokens, int start, TokenType type);
public:
    Parser(Context *context);
    Command *parse(QList<Token> tokens, int start);
};

#endif // PARSER_H
