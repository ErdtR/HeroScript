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

PlusOperator::PlusOperator(Expression *firstOperand, Expression *secondOperand)
{
    _firstOperand = firstOperand;
    _secondOperand = secondOperand;
}

QString PlusOperator::getValue()
{
    bool firstOk, secondOk;
    int firstNumber = _firstOperand->getValue().toInt(&firstOk, 10);
    int secondNumber = _secondOperand->getValue().toInt(&secondOk, 10);

    if(firstOk && secondOk)
    {
        return QString::number(firstNumber + secondNumber);
    }
    else
    {
        return _firstOperand->getValue() + _secondOperand->getValue();
    }
}

MinusOperator::MinusOperator(Expression *firstOperand, Expression *secondOperand)
{
    _firstOperand = firstOperand;
    _secondOperand = secondOperand;
}

QString MinusOperator::getValue()
{
    bool firstOk, secondOk;
    int firstNumber = _firstOperand->getValue().toInt(&firstOk, 10);
    int secondNumber = _secondOperand->getValue().toInt(&secondOk, 10);

    if(firstOk && secondOk)
    {
        return QString::number(firstNumber - secondNumber);
    }
}

DivisionOperator::DivisionOperator(Expression *firstOperand, Expression *secondOperand)
{
    _firstOperand = firstOperand;
    _secondOperand = secondOperand;
}

QString DivisionOperator::getValue()
{
    bool firstOk, secondOk;
    int firstNumber = _firstOperand->getValue().toInt(&firstOk, 10);
    int secondNumber = _secondOperand->getValue().toInt(&secondOk, 10);

    if(firstOk && secondOk)
    {
        return QString::number(firstNumber/secondNumber);
    }
}

MultiplicationOperator::MultiplicationOperator(Expression *firstOperand, Expression *secondOperand)
{
    _firstOperand = firstOperand;
    _secondOperand = secondOperand;
}

QString MultiplicationOperator::getValue()
{
    bool firstOk, secondOk;
    int firstNumber = _firstOperand->getValue().toInt(&firstOk, 10);
    int secondNumber = _secondOperand->getValue().toInt(&secondOk, 10);

    if(firstOk && secondOk)
    {
        return QString::number(firstNumber*secondNumber);
    }
}

EqualOperator::EqualOperator(Expression *firstOperand, Expression *secondOperand)
{
    _firstOperand = firstOperand;
    _secondOperand = secondOperand;
}

QString EqualOperator::getValue()
{
    if(_firstOperand->getValue() == _secondOperand->getValue())
    {
        return "1";
    }
    else
    {
        return "0";
    }
}

NotEqualOperator::NotEqualOperator(Expression *firstOperand, Expression *secondOperand)
{
    _firstOperand = firstOperand;
    _secondOperand = secondOperand;
}

QString NotEqualOperator::getValue()
{
    if(_firstOperand->getValue() == _secondOperand->getValue())
    {
        return "0";
    }
    else
    {
        return "1";
    }
}

LessOperator::LessOperator(Expression *firstOperand, Expression *secondOperand)
{
    _firstOperand = firstOperand;
    _secondOperand = secondOperand;
}

QString LessOperator::getValue()
{
    bool firstOk, secondOk;
    int firstNumber = _firstOperand->getValue().toInt(&firstOk, 10);
    int secondNumber = _secondOperand->getValue().toInt(&secondOk, 10);

    if(firstOk && secondOk)
    {
        if(firstNumber < secondNumber)
            return "1";
        else
            return "0";
    }
    else
    {
        if(_firstOperand < _secondOperand)
            return "1";
        else
            return "0";
    }
}

MoreOperator::MoreOperator(Expression *firstOperand, Expression *secondOperand)
{
    _firstOperand = firstOperand;
    _secondOperand = secondOperand;
}

QString MoreOperator::getValue()
{
    bool firstOk, secondOk;
    int firstNumber = _firstOperand->getValue().toInt(&firstOk, 10);
    int secondNumber = _secondOperand->getValue().toInt(&secondOk, 10);

    if(firstOk && secondOk)
    {
        if(firstNumber < secondNumber)
            return "0";
        else
            return "1";
    }
    else
    {
        if(_firstOperand < _secondOperand)
            return "0";
        else
            return "1";
    }
}
