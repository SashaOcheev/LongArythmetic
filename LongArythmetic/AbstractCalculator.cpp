#include "AbstractCalculator.h"

BigInt AbstractCalculator::Calculate(const std::vector<digit>& number1, const std::string & op, const std::vector<digit>& number2) const
{
    auto a = std::make_unique<BigInt>(number1);
    BigInt b(number2);

    auto command = CreateCommand(op, a.get(), b);
    command->Execute();
    return *a;
}

AbstractCalculator::~AbstractCalculator()
{
}
