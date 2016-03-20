#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

typedef short digit;

class LongAryth
{
public:
	LongAryth();
	LongAryth(const std::vector<digit> number);
	LongAryth(long long number);

	void addInsignificant0(size_t targetSize);
	void removeInsignificant0();

	LongAryth operator+(const LongAryth &number);
	LongAryth operator*(const LongAryth &number);
	LongAryth operator-(const LongAryth &number); //for a - b. if a < b return 0;
    LongAryth operator/(const LongAryth &number);

	bool operator==(const LongAryth &number) const;
	bool operator!=(const LongAryth &number) const;
	bool operator<(const LongAryth &number) const;
	bool operator<=(const LongAryth &number) const;
	bool operator>(const LongAryth &number) const;
	bool operator>=(const LongAryth &number) const;

	friend std::ostream &operator<<(std::ostream &os, LongAryth &n);

private:
    std::vector<digit>::const_iterator begin() const;
    std::vector<digit>::const_iterator end() const;
    std::vector<digit>::iterator begin();
    std::vector<digit>::iterator end();

    size_t GetSize() const;
    void EditOverflowDigits();
    void ResizeAndFill(size_t size, digit val);
    void Push(digit val);
    digit Pop();
    digit &operator[](size_t i);

	std::vector<digit> m_number;
};
