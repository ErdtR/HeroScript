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

class Operator : public Expression
{
public:
    Operator();
};

class Variable : public Expression
{
private:
    QString _varName;
public:
    Variable(QString varName, Context *context);
    QString getValue();
};

#endif // EXPRESSION_H
