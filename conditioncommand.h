#ifndef CONDITIONCOMMAND_H
#define CONDITIONCOMMAND_H

#include "command.h"

class ConditionCommand : public Command
{
public:
    ConditionCommand();
private:
    Command* _trueCommand;
    Command* _falseCommand;
};

class IfCommand : public ConditionCommand
{
public:
    IfCommand();
    Command* getNextCommand();
    void execute();
};

class WhileCommand : public ConditionCommand
{
public:
    WhileCommand();
    Command* getNextCommand();
    void execute();
};

#endif // CONDITIONCOMMAND_H
