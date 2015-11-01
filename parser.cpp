#include "parser.h"

Parser::Parser(Context *context)
{
    _context = context;
}

Command *Parser::parse(QList<Token> tokens, int start, int end)
{
    for(int i = start; i<end; i++)
    {
        Token token = tokens[i];
        int endIndex;
        Command *resultCommand;
        switch(token.getType()){
        case var:
            endIndex = indexOf(tokens, i, semicolon);
            resultCommand = parseVarCommand(tokens, i, endIndex);
            resultCommand->setNextCommand(parse(tokens, endIndex+1, end));
            return resultCommand;
        case assigment:
            endIndex = indexOf(tokens, i, semicolon);
            resultCommand = parseAssigmentCommand(tokens, i-1, endIndex);
            resultCommand->setNextCommand(parse(tokens, endIndex+1, end));
            return resultCommand;
        case heroObject:
            endIndex = indexOf(tokens, i, semicolon);
            resultCommand = parseHeroCommand(tokens, i, endIndex);
            resultCommand->setNextCommand(parse(tokens, endIndex+1, end));
            return resultCommand;
        case whileToken:
            resultCommand = parseWhileCommand(tokens, i);
            return resultCommand;
        case ifToken:
            resultCommand = parseIfCommand(tokens, i);
            return resultCommand;
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

AssigmentCommand *Parser::parseAssigmentCommand(QList<Token> tokens, int start, int end)
{
    AssigmentCommand *assCommand;
    QString name = tokens[start].getData();
    Expression *expr = parseExp(tokens, start+2, end-1);
    assCommand = new AssigmentCommand(_context, name, expr);
    return assCommand;
}

Command *Parser::parseHeroCommand(QList<Token> tokens, int start, int end)
{
    if(tokens[start+1].getType() == dot)
    {
        Command *resultCommand;
        Expression *exp;
        switch(tokens[start+2].getType()){
        case goMethod:
            resultCommand = new GoCommand();
            return resultCommand;
        case sayMethod:
            exp = parseExp(tokens, start+4, end-2);
            resultCommand = new SayCommand(exp);
            return resultCommand;
        case turnRightMethod:
            resultCommand = new TurnRightCommand();
            return resultCommand;
        case turnLeftMethod:
            resultCommand = new TurnLeftCommand();
            return resultCommand;
        }
    }
}

Expression *Parser::parseExp(QList<Token> tokens, int start, int end)
{
    if(end-start == 0)
    {
        //constant or variable
        if(tokens[start].getType() == number || tokens[start].getType() == string)
        {
            return new Constant(tokens[start].getData(), _context);
        }
        else if(tokens[start].getType() == variable)
        {
            return new Variable(tokens[start].getData(), _context);
        }
    }
    else
    {
        //operator
        // припустимо, що в одному виразі може бути тільки одна оперція
        // просто мені дуже хочеться спати
        Expression *firstOperand = parseExp(tokens, start, start);
        Expression *secondOperand = parseExp(tokens, end, end);

        switch (tokens[start+1].getType()) {
        case plus:
            return new PlusOperator(firstOperand, secondOperand);
        case minus:
            return new MinusOperator(firstOperand, secondOperand);
        case division:
            return new DivisionOperator(firstOperand, secondOperand);
        case multiplication:
            return new MultiplicationOperator(firstOperand, secondOperand);
        case logicEqual:
            return new EqualOperator(firstOperand, secondOperand);
        case logicNotEqual:
            return new NotEqualOperator(firstOperand, secondOperand);
        case logicLess:
            return new LessOperator(firstOperand, secondOperand);
        case logicMore:
            return new MoreOperator(firstOperand, secondOperand);
        }
    }
}

WhileCommand *Parser::parseWhileCommand(QList<Token> tokens, int start)
{
    int indexOfrightParenthesis;
    if(tokens[start+1].getType() == leftParenthesis)
    {
       indexOfrightParenthesis = indexOfPair(tokens, start+2, leftParenthesis, rightParenthesis);
    }
    Expression *exp = parseExp(tokens, start+2,indexOfrightParenthesis-1);
    int indexOfLeftCurly = indexOf(tokens,indexOfrightParenthesis, leftCurlyBrace);
    int indexOfRightCurly = indexOfPair(tokens,indexOfLeftCurly+1, leftCurlyBrace, rightCurlyBrace);

    Command *trueCommand = parse(tokens, indexOfLeftCurly, indexOfRightCurly);
    Command *falseCommand = parse(tokens, indexOfRightCurly+1, tokens.length());

    WhileCommand *resultCommand = new WhileCommand(exp, trueCommand, falseCommand);
    return resultCommand;
}

IfCommand *Parser::parseIfCommand(QList<Token> tokens, int start)
{
    int indexOfrightParenthesis;
    IfCommand *resultCommand;
    if(tokens[start+1].getType() == leftParenthesis)
    {
        indexOfrightParenthesis = indexOfPair(tokens, start+2, leftParenthesis, rightParenthesis);
    }
    Expression *exp = parseExp(tokens, start+2,indexOfrightParenthesis-1);

    int indexOfLeftCurly = indexOf(tokens,indexOfrightParenthesis, leftCurlyBrace);
    int indexOfRightCurly = indexOfPair(tokens,indexOfLeftCurly+1, leftCurlyBrace, rightCurlyBrace);

    Command *trueCommand = parse(tokens, indexOfLeftCurly, indexOfRightCurly);

    if(tokens[indexOfRightCurly+1].getType() == elseToken)
    {
        indexOfLeftCurly = indexOf(tokens, indexOfRightCurly+1, leftCurlyBrace);
        indexOfRightCurly = indexOfPair(tokens,indexOfLeftCurly+1, leftCurlyBrace, rightCurlyBrace);
        Command *falseCommand = parse(tokens, indexOfLeftCurly, indexOfRightCurly);
        resultCommand = new IfCommand(exp, trueCommand, falseCommand);
    }
    else
    {
        resultCommand = new IfCommand(exp, trueCommand, NULL);
    }

    resultCommand->setNextCommand(parse(tokens, indexOfRightCurly+1, tokens.length()));
    return resultCommand;
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

int Parser::indexOfPair(QList<Token> tokens, int start, TokenType left, TokenType right)
{
    int length = tokens.length();
    int count = 0;
    for(int i = start; i<length; i++)
    {
        if(tokens[i].getType() == left)
        {
            count++;
        }
        else if(tokens[i].getType() == right)
        {
            if(count == 0)
                return i;
            else
                count--;
        }
    }
}

