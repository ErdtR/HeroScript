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
