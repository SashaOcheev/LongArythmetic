#include "Parser.h"
#include <algorithm>
#include <string>
#include "PlusCommand.h"
#include "DivisionCommand.h"
#include "ProductCommand.h"
#include "MinusCommand.h"

Parser::Parser(std::ifstream &inputFile, std::ofstream &outputFile)
{
    input = std::move(inputFile);
    output = std::move(outputFile);
}

void Parser::Run()
{
    std::string str;
    while (std::getline(input, str))
    {
        std::vector<digit> number1;
        std::string op;
        std::vector<digit> number2;
        
        for (auto ch : str)
        {
            if (ch <= '9' && ch >= '0')
            {
                if (op.empty())
                {
                    number1.push_back(ch - '0');
                }
                else
                {
                    number2.push_back(ch - '0');
                }
            }
            else
            {
                op.push_back(ch);
            }
        }
        auto res = Calculate(number1, op, number2);
        output << res << std::endl;
    }
}


Parser::~Parser()
{
}

BigInt Parser::Calculate(const std::vector<digit> &number1, const std::string &op, const std::vector<digit> &number2) const
{
    auto a = std::make_unique<BigInt>(number1);
    BigInt b(number2);

    auto command = CreateCommand(op, a.get(), b);
    command->Execute();
    return *a;
}

std::unique_ptr<Command> Parser::CreateCommand(const std::string &op, BigInt* number1, const BigInt &number2) const
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

