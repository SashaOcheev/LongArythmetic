#pragma once
#include <fstream>
#include "BigInt.h"
#include "AbstractCalculator.h"
#include <set>

class FileHandler
{
public:
    FileHandler(std::ifstream &inputFile, std::ofstream &outputFile);

    void Run();

    ~FileHandler();

private:
    AbstractCalculator *calculator;
    std::ifstream input;
    std::ofstream output;
    std::set<char> operators = { '-', '+', '/', '*' };
};

