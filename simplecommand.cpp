#include "simplecommand.h"

SimpleCommand::SimpleCommand()
{

}


VarCommand::VarCommand(Context *context, QString name, Expression *exp)
{
    _context = context;
    _name = name;
    _exp = exp;
}

void VarCommand::setNextCommand(Command *command)
{
    _nextCommand = command;
}

Command *VarCommand::getNextCommand()
{
    return _nextCommand;
}

void VarCommand::execute()
{
    _context->addVariable(_name, _exp->getValue());
    qDebug()<<"Var Executed";
}

AssigmentCommand::AssigmentCommand(Context *context, QString variable, Expression *exp)
{
    _context = context;
    _variable = variable;
    _exp = exp;
}

void AssigmentCommand::setNextCommand(Command *command)
{
    _nextCommand = command;
}

Command *AssigmentCommand::getNextCommand()
{
    return _nextCommand;
}

void AssigmentCommand::execute()
{
    _context->setVariable(_variable, _exp->getValue());
    qDebug()<<"Assigment Executed";
}

GoCommand::GoCommand()
{

}

Command *GoCommand::getNextCommand()
{
    return _nextCommand;
}

void GoCommand::setNextCommand(Command *command)
{
    _nextCommand = command;
}

void GoCommand::execute()
{
    qDebug()<<"Go Command Executed!";
}

SayCommand::SayCommand(Expression *exp)
{
    _exp = exp;
}

Command *SayCommand::getNextCommand()
{
    return _nextCommand;
}

void SayCommand::setNextCommand(Command *command)
{
    _nextCommand = command;
}

void SayCommand::execute()
{
    qDebug()<<"Hero say: "<<_exp->getValue();
}

Command *TurnRightCommand::getNextCommand()
{
    return _nextCommand;
}

void TurnRightCommand::setNextCommand(Command *command)
{
    _nextCommand = command;
}

void TurnRightCommand::execute()
{
    qDebug()<< "Turn Right Executed!";
}

Command *TurnLeftCommand::getNextCommand()
{
    return _nextCommand;
}

void TurnLeftCommand::setNextCommand(Command *command)
{
    _nextCommand = command;
}

void TurnLeftCommand::execute()
{
    qDebug()<<"Turn Left Executed";
}
