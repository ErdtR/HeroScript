#include "expression.h"


Constant::Constant(QString value, Context *context) : _value(value)
{
    _context = context;
}

QString Constant::getValue()
{
    return _value;
}

Variable::Variable(QString varName, Context *context) : _varName(varName)
{
    _varName = varName;
    _context = context;
}

QString Variable::getValue()
{
    return _context->getVariable(_varName);
}
