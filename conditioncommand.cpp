#include "conditioncommand.h"

ConditionCommand::ConditionCommand()
{

}


WhileCommand::WhileCommand(Expression *exp, Command *trueComm, Command *falseComm)
{
    _exp = exp;
    _trueCommand = trueComm;
    _falseCommand = falseComm;
}

Command *WhileCommand::getNextCommand()
{
    return _falseCommand;
}

void WhileCommand::setNextCommand(Command *command)
{

}

void WhileCommand::execute()
{
    while(_exp->getValue() == "1")
    {
        Command *tmpComm = _trueCommand;
        while(tmpComm != NULL)
        {
            tmpComm->execute();
            tmpComm = tmpComm->getNextCommand();
        }
    }
}

IfCommand::IfCommand(Expression *exp, Command *trueComm, Command *falseComm)
{
    _exp = exp;
    _trueCommand = trueComm;
    _falseCommand = falseComm;
}

void IfCommand::setNextCommand(Command *command)
{
    _nextCommand = command;
}

Command *IfCommand::getNextCommand()
{
    return _nextCommand;
}

void IfCommand::execute()
{
    if(_exp->getValue() == "1")
    {
        Command *tmpComm = _trueCommand;
        while(tmpComm != NULL)
        {
            tmpComm->execute();
            tmpComm = tmpComm->getNextCommand();
        }
    }
    else
    {
        Command *tmpComm = _falseCommand;
        while(tmpComm != NULL)
        {
            tmpComm->execute();
            tmpComm = tmpComm->getNextCommand();
        }
    }
}
