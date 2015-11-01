#include "interpreter.h"

Interpreter::Interpreter()
{

}

void Interpreter::interpret(Command *command)
{
    while(command != NULL)
    {
        command->execute();
        command = command->getNextCommand();
    }
}

