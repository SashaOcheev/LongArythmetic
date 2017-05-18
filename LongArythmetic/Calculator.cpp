#include "Calculator.h"
#include "PlusCommand.h"
#include "MinusCommand.h"
#include "ProductCommand.h"
#include "DivisionCommand.h"

Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}

std::unique_ptr<Command> Calculator::CreateCommand(const std::string & op, BigInt * number1, const BigInt & number2) const
{
    if (op == "+")
    {
        return std::make_unique<PlusCommand>(number1, number2);
    }
    else if (op == "-")
    {
        return std::make_unique<MinusCommand>(number1, number2);
    }
    else if (op == "*")
    {
        return std::make_unique<ProductCommand>(number1, number2);
    }
    else if (op == "/")
    {
        return std::make_unique<DivisionCommand>(number1, number2);
    }
}
