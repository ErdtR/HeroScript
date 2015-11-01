#ifndef CONDITIONCOMMAND_H
#define CONDITIONCOMMAND_H

#include "command.h"

class ConditionCommand : public Command
{
public:
    ConditionCommand();
protected:
    Command* _trueCommand;
    Command* _falseCommand;
    Command* _nextCommand;
};

class IfCommand : public ConditionCommand
{
private:
    Expression *_exp;
public:
    IfCommand(Expression *exp, Command *trueComm, Command *falseComm);
    void setNextCommand(Command *command);
    Command *getNextCommand();
    void execute();
};

class WhileCommand : public ConditionCommand
{
private:
    Expression *_exp;
public:
    WhileCommand(Expression *exp, Command *trueComm, Command *falseComm);
    Command *getNextCommand();
    void setNextCommand(Command *command);
    void execute();
};

#endif // CONDITIONCOMMAND_H
