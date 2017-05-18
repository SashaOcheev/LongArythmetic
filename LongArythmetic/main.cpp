#include <iostream>
#include "BigInt.h"
#include "BigIntTest.h"
#include "Parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    BigIntTest();

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    Parser parser(input, output);
    parser.Run();
}