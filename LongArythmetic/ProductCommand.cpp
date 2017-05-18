#include "ProductCommand.h"

ProductCommand::ProductCommand(BigInt *number1, const BigInt &number2)
{
    a = number1;
    b = number2;
}

void ProductCommand::Execute()
{
    a->operator*=(b);
}

ProductCommand::~ProductCommand()
{
}
