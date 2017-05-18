#include "PlusCommand.h"

PlusCommand::PlusCommand(BigInt *number1, const BigInt &number2)
{
    a = number1;
    b = number2;
}

void PlusCommand::Execute()
{
    a->operator+=(b);
}

PlusCommand::~PlusCommand()
{
}
