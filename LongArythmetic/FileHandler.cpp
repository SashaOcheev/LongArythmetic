#include "FileHandler.h"
#include <algorithm>
#include <string>
#include "Calculator.h"

FileHandler::FileHandler(std::ifstream &inputFile, std::ofstream &outputFile)
{
    input = std::move(inputFile);
    output = std::move(outputFile);
    calculator = new Calculator();
}

void FileHandler::Run()
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
        auto res = calculator->Calculate(number1, op, number2);
        output << res << std::endl;
    }
}


FileHandler::~FileHandler()
{
    delete calculator;
}


