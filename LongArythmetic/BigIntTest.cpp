#include <cassert>
#include "BigIntTest.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void DividedEndsBy0()
{
    BigInt a(20000);
    BigInt b(2);
    a /= b;
    assert(a == 10000);
}

void DividedWith0()
{
    BigInt a(2000202);
    BigInt b(2);
    a /= b;
    assert(a == 1000101);
}

void BigIntTest()
{
    BigInt a(123);
    BigInt b(321);

    for (BigInt i = 200; i > 0; --i)
    {
        BigInt a1 = 100;
        a1 -= i;
    }

    assert(a + b == 444);
    assert(b + a == 444);

    assert(a - b == 0);
    assert(b - a == 198);
    assert(a - a == 0);

    assert(a * b == 39483);
    assert(b * a == 39483);
    assert(a * 0 == 0);

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

    c = a;
    c /= b;
    assert(c == 0);

    c = b;
    c /= a;
    assert(c == 2);

    c = a / b;
    assert(a == 123);
    assert(c == 0);

    c = b / a;
    assert(b == 321);
    assert(c == 2);

    c = a / a;
    assert(c == 1);

    c = BigInt(1232) / BigInt(10);
    assert(c == 123);
    c = BigInt(1232) % BigInt(10);
    assert(c == 2);

    try
    {
        a / 0;
    }
    catch (logic_error &ex)
    {
        ex.what() == "dividing by zero";
    }


    c = a;
    c %= b;
    assert(c == 123);

    c = b;
    c %= a;
    assert(c == 75);

    c = a % b;
    assert(a == 123);
    assert(c == 123);

    c = b % a;
    assert(b == 321);
    assert(c == 75);

    c = a % a;
    assert(c == 0);

    try
    {
        a % 0;
    }
    catch (logic_error &ex)
    {
        ex.what() == "dividing by zero";
    }

    DividedEndsBy0();
    DividedWith0();
}
