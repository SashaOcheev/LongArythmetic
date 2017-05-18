#pragma once
#include <fstream>
#include <vector>
#include "BigInt.h"
#include <memory>
#include "Command.h"

class AbstractCalculator
{
public:
    BigInt Calculate(const std::vector<digit> &number1, const std::string &op, const std::vector<digit> &number2) const;

    virtual ~AbstractCalculator();

protected:
    virtual std::unique_ptr<Command> CreateCommand(const std::string &op, BigInt* number1, const BigInt &number2) const = 0;
};

