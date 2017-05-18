#pragma once
#include "AbstractCalculator.h"
class Calculator :
    public AbstractCalculator
{
public:
    Calculator();

    ~Calculator();

protected:
    std::unique_ptr<Command> CreateCommand(const std::string &op, BigInt* number1, const BigInt &number2) const override;
};

