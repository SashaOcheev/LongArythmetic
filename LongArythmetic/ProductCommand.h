#pragma once
#include "Command.h"

class ProductCommand :
    public Command
{
public:
    ProductCommand(BigInt *number1, const BigInt &number2);

    void Execute() override;

    ~ProductCommand();
};
