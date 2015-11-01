#ifndef SIMPLECOMMAND_H
#define SIMPLECOMMAND_H
#include "command.h"

class SimpleCommand : public Command
{
public:
    SimpleCommand();
protected:
    Command *_nextCommand;
};

class VarCommand : public SimpleCommand
{
private:
    QString _name;
    Expression *_exp;
public:
    VarCommand(Context *context, QString name, Expression *exp);
    void setNextCommand(Command *command);
    Command* getNextCommand();
    void execute();
};

class GoCommand : public SimpleCommand
{
public:
    GoCommand();
    Command* getNextCommand();
    void execute();
};

class SayCommand : public SimpleCommand
{
public:
    SayCommand();
    Command* getNextCommand();
    void execute();
};

#endif // SIMPLECOMMAND_H
