#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "QString"
#include "context.h"

class Expression
{
public:
    virtual QString getValue()=0;
protected:
    Context *_context;
};

class Constant: public Expression
{
private:
    QString _value;
public:
    Constant(QString value, Context *context);
    QString getValue();
};

class Variable : public Expression
{
private:
    QString _varName;
public:
    Variable(QString varName, Context *context);
    QString getValue();
};

class Operator : public Expression
{
public:

protected:
    Expression *_firstOperand;
    Expression *_secondOperand;
};

class PlusOperator : public Operator
{
public:
    PlusOperator(Expression *firstOperand, Expression *secondOperand);
    QString getValue();
};

class MinusOperator : public Operator
{
public:
    MinusOperator(Expression *firstOperand, Expression *secondOperand);
    QString getValue();
};

class DivisionOperator : public Operator
{
public:
    DivisionOperator(Expression *firstOperand, Expression *secondOperand);
    QString getValue();
};

class MultiplicationOperator : public Operator
{
public:
    MultiplicationOperator(Expression *firstOperand, Expression *secondOperand);
    QString getValue();
};

class EqualOperator : public Operator
{
public:
    EqualOperator(Expression *firstOperand, Expression *secondOperand);
    QString getValue();
};

class NotEqualOperator : public Operator
{
public:
    NotEqualOperator(Expression *firstOperand, Expression *secondOperand);
    QString getValue();
};

class LessOperator : public Operator
{
public:
    LessOperator(Expression *firstOperand, Expression *secondOperand);
    QString getValue();
};

class MoreOperator : public Operator
{
public:
    MoreOperator(Expression *firstOperand, Expression *secondOperand);
    QString getValue();
};

#endif // EXPRESSION_H
