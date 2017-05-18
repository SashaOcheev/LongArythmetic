#pragma once
#include "Command.h"

class MinusCommand :
    public Command
{
public:
    MinusCommand(BigInt *number1, const BigInt &number2);

    void Execute() override;

    ~MinusCommand();
};

