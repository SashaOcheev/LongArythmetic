
#include "aryth.h"
#include <iostream>

using namespace std;

int main()
{
    LongAryth a(123);
    LongAryth b(321);
    auto sum = a + b;
    auto diff = b - a;
    auto prod = a * b;

    cout << sum << endl;
    cout << diff << endl;
    cout << prod << endl;

	return 0;
}