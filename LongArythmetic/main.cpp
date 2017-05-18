#include <iostream>
#include "BigInt.h"
#include "BigIntTest.h"
#include "FileHandler.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    BigIntTest();

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    FileHandler fileHandler(input, output);
    fileHandler.Run();
}