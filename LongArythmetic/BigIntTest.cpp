#include <cassert>
#include "BigIntTest.h"
#include <iostream>
using namespace std;

void BigIntTest()
{
    BigInt a(123);
    BigInt b(321);

    assert(a + b == 444);
    assert(b + a == 444);

    assert(a - b == 0);
    assert(b - a == 198);

    assert(a * b == 39483);
    assert(b * a == 39483);

    assert(a < b == true);
    assert(b < a == false);

    assert(a <= b == true);
    assert(b <= a == false);

    assert(a > b == false);
    assert(b > a == true);

    assert(a >= b == false);
    assert(b >= a == true);

    assert(a == b == false);

    assert(a != b == true);

    BigInt c(a);
    BigInt oldC = c;
    assert(++c == oldC + 1);
    assert(c == oldC + 1);

    oldC = c;
    assert(c++ == oldC);
    assert(c == oldC + 1);

    oldC = c;
    c += 10;
    assert(c == oldC + 10);
    oldC = c;
    assert((c += 10) == oldC + 10);

    oldC = c;
    c *= 10;
    assert(c == oldC * 10);
    oldC = c;
    assert((c *= 10) == oldC * 10);

    oldC = c;
    c -= 10;
    assert(c == oldC - 10);
    oldC = c;
    assert((c -= 10) == oldC - 10);
}
