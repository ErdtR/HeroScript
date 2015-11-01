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

class AssigmentCommand : public SimpleCommand
{
private:
    QString _variable;
    Expression *_exp;
public:
    AssigmentCommand(Context *context, QString variable, Expression *exp);
    void setNextCommand(Command *command);
    Command *getNextCommand();
    void execute();
};

class GoCommand : public SimpleCommand
{
public:
    GoCommand();
    Command *getNextCommand();
    void setNextCommand(Command *command);
    void execute();
};

class SayCommand : public SimpleCommand
{
private:
    Expression *_exp;
public:
    SayCommand(Expression *exp);
    Command *getNextCommand();
    void setNextCommand(Command *command);
    void execute();
};

class TurnLeftCommand : public SimpleCommand
{
public:
    Command *getNextCommand();
    void setNextCommand(Command *command);
    void execute();
};

class TurnRightCommand : public SimpleCommand
{
public:
    Command *getNextCommand();
    void setNextCommand(Command *command);
    void execute();
};

#endif // SIMPLECOMMAND_H
