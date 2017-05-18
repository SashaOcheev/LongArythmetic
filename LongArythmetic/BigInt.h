#pragma once
#include <vector>
#include <iostream>

typedef short digit;

class BigInt
{
public:
    BigInt() = default;
	BigInt(const std::vector<digit> &number);
	BigInt(long long number);
    BigInt(const BigInt &source);

    const BigInt operator++();
    const BigInt operator++(int);
    const BigInt operator--();
    const BigInt operator--(int);

    const BigInt operator+=(const BigInt &number);
    const BigInt operator*=(const BigInt &number);
    const BigInt operator-=(const BigInt &number);
    const BigInt operator/=(const BigInt &number);
    const BigInt operator%=(const BigInt &number);

	const BigInt operator+(const BigInt &number) const;
	const BigInt operator*(const BigInt &number) const;
    const BigInt operator-(const BigInt &number) const;
    const BigInt operator/(const BigInt &number) const;
    const BigInt operator%(const BigInt &number) const;

	bool operator==(const BigInt &number) const;
	bool operator!=(const BigInt &number) const;
	bool operator<(const BigInt &number) const;
	bool operator<=(const BigInt &number) const;
	bool operator>(const BigInt &number) const;
	bool operator>=(const BigInt &number) const;

	friend std::ostream &operator<<(std::ostream &os, BigInt &n);

private:
    std::vector<digit>::const_iterator begin() const;
    std::vector<digit>::const_iterator end() const;
    std::vector<digit>::iterator begin();
    std::vector<digit>::iterator end();

    size_t GetSize() const;
    void EditOverflowDigits();
    void ResizeAndFill(size_t size, digit val);
    void Push(digit val);
    void PushFront(digit val);
    digit Pop();
    digit &operator[](size_t i);
    const digit &operator[](size_t i) const;
    void addInsignificant0(size_t targetSize);
    void removeInsignificant0();

	std::vector<digit> m_number;
};
