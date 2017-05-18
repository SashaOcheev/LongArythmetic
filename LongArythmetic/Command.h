#pragma once
#include "BigInt.h"
#include <ostream>

//ostream is reciever

class Command
{
public:
    virtual void Execute() = 0;

    virtual ~Command() = default;

protected:
    BigInt *a;
    BigInt b;
    std::ostream *stream;
};

