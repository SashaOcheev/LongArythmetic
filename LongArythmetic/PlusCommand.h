#pragma once
#include "Command.h"

class PlusCommand :
    public Command
{
public:
    PlusCommand(BigInt *number1, const BigInt &number2);

    void Execute() override;

    ~PlusCommand();
};

