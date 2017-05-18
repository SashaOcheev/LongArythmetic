#pragma once
#include "Command.h"

class DivisionCommand :
    public Command
{
public:
    DivisionCommand(BigInt *number1, const BigInt &number2);

    void Execute() override;

    ~DivisionCommand();
};

