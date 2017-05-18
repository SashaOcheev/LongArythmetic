#include "DivisionCommand.h"

DivisionCommand::DivisionCommand(BigInt *number1, const BigInt &number2)
{
    a = number1;
    b = number2;
}

void DivisionCommand::Execute()
{
    a->operator/=(b);
}

DivisionCommand::~DivisionCommand()
{
}
