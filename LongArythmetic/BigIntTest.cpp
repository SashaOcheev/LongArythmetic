#include <cassert>
#include "BigIntTest.h"


void BigIntTest()
{
    BigInt a(123);
    BigInt b(321);

    assert(a + b == BigInt(444));
    assert(b + a == BigInt(444));
    assert(a - b == BigInt(0));
    assert(b - a == BigInt(198));
    assert(a * b == BigInt(39483));
    assert(b * a == BigInt(39483));
    assert(a < b == true);
    assert(a <= b == true);
    assert(b < a == false);
    assert(b <= a == false);
    assert(a > b == false);
    assert(a >= b == false);
    assert(b > a == true);
    assert(b >= a == true);
    assert(a == b == false);
    assert(a != b == true);
}
