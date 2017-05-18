#pragma once
#include <fstream>
#include <vector>
#include "BigInt.h"
#include <memory>
#include "Command.h"

class Parser
{
public:
    Parser(std::ifstream &inputFile, std::ofstream &outputFile);

    void Run();

    ~Parser();

private:
    BigInt Calculate(const std::vector<digit> &number1, const std::string &op, const std::vector<digit> &number2) const;
    std::unique_ptr<Command> CreateCommand(const std::string &op, BigInt* number1, const BigInt &number2) const;

    std::ifstream input;
    std::ofstream output;
};

