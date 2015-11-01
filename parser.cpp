#include "parser.h"

Parser::Parser(Context *context)
{
    _context = context;
}

Command *Parser::parse(QList<Token> tokens, int start)
{
    int length = tokens.length();
    for(int i = start; i<length; i++)
    {
        Token token = tokens[i];
        switch(token.getType()){
        case var:
            int endIndex = indexOf(tokens, i, semicolon);
            VarCommand * varComm = parseVarCommand(tokens, i, endIndex);
            varComm->setNextCommand(parse(tokens, endIndex+1));
            return varComm;
        }
    }

    return NULL;
}

VarCommand *Parser::parseVarCommand(QList<Token> tokens, int start, int end)
{
    VarCommand *varComm;
    QString name = tokens[start+1].getData();
    Expression *expr = parseExp(tokens, start+3, end-1);
    varComm = new VarCommand(_context, name, expr);
    return varComm;
}

Expression *Parser::parseExp(QList<Token> tokens, int start, int end)
{
    if(end-start == 0)
    {
        //constant or variable
        if(tokens[start].getType() == number || tokens[start].getType() == string)
        {
            qDebug()<<"Constant created";
            return new Constant(tokens[start].getData(), _context);
        }
        else if(tokens[start].getType() == variable)
        {
            qDebug()<<"Variable created";
            return new Variable(tokens[start].getData(), _context);
        }
    }
    else
    {
        //operator
        // припустимо, в одному виразі може бути тільки одна оперція
        // просто мені дуже хочеться спати

    }
}

int Parser::indexOf(QList<Token> tokens, int start, TokenType type)
{
    int length = tokens.length();
    for(int i = start; i<length; i++)
    {
        if(tokens[i].getType() == type)
            return i;
    }
}

