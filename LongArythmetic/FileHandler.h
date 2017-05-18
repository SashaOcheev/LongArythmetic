#pragma once
#include <fstream>
#include "BigInt.h"
#include "AbstractCalculator.h"

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
};

