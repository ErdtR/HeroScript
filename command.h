#ifndef COMMAND_H
#define COMMAND_H
#include <QtCore>
#include <expression.h>
#include <context.h>

class Command
{
public:
    Command();
    virtual Command* getNextCommand()=0;
    virtual void setNextCommand(Command *command) = 0;
    virtual void execute()=0;
protected:
    Context *_context;
};

#endif // COMMAND_H
