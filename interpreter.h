#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "command.h"

class Interpreter
{
public:
    Interpreter();
    void interpret(Command *command);

signals:

public slots:
};

#endif // INTERPRETER_H
