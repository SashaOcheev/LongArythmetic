#include "MinusCommand.h"

MinusCommand::MinusCommand(BigInt *number1, const BigInt &number2)
{
    a = number1;
    b = number2;
}

void MinusCommand::Execute()
{
    a->operator-=(b);
}

MinusCommand::~MinusCommand()
{
}
