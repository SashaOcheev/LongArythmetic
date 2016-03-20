#include "aryth.h"

LongAryth::LongAryth()
{

}

LongAryth::LongAryth(const std::vector<digit> number)
{
    m_number = number;
}

LongAryth::LongAryth(long long number)
{
	do
	{
		Push(number % 10);
		number /= 10;
	} while (number);
}

std::vector<digit>::iterator LongAryth::begin()
{
	return m_number.begin();
}

std::vector<digit>::iterator LongAryth::end()
{
	return m_number.end();
}

std::vector<digit>::const_iterator LongAryth::begin() const
{
    return m_number.cbegin();
}

std::vector<digit>::const_iterator LongAryth::end() const
{
    return m_number.end();
}

void LongAryth::addInsignificant0(size_t targetSize)
{
	while (GetSize() < targetSize)
		Push(0);
}

void LongAryth::removeInsignificant0()
{
	while (GetSize() > 1)
	{
		if (m_number.back() == 0)
			Pop();
		else
			return;
	}
}

size_t LongAryth::GetSize() const
{
	return m_number.size();
}

void LongAryth::ResizeAndFill(size_t size, digit val)
{
	m_number.resize(size);
	std::fill(m_number.begin(), m_number.end(), val);
}

void LongAryth::Push(digit val)
{
	m_number.push_back(val);
}

digit LongAryth::Pop()
{
	digit t = m_number.back();
	m_number.pop_back();
	return t;
}

void LongAryth::EditOverflowDigits()
{
	for (size_t i = 0; i < GetSize(); i++)
	{
		digit t = m_number[i];
		m_number[i] = t % 10;
		if (t / 10 > 0)
		{
			if (i == GetSize() - 1)
				Push(0);
			m_number[i + 1] += t / 10;
		}
	}
}

digit &LongAryth::operator[](size_t i)
{
	return m_number[i];
}

LongAryth LongAryth::operator+(const LongAryth &number)
{
    LongAryth tempNumber(number);

	size_t maxSize = std::max(tempNumber.GetSize(), GetSize());
	addInsignificant0(maxSize);
    tempNumber.addInsignificant0(maxSize);

	LongAryth res;
	for (size_t i = 0; i < tempNumber.GetSize(); i++)
		res.Push(m_number[i] + tempNumber[i]);

	removeInsignificant0();
    tempNumber.removeInsignificant0();

	res.EditOverflowDigits();
	return res;
}

LongAryth LongAryth::operator*(const LongAryth &number)
{
    LongAryth tempNumber(number);

	LongAryth res;
	res.ResizeAndFill(tempNumber.GetSize() + GetSize(), 0);

	for (size_t i = 0; i < GetSize(); i++)
	{
		for (size_t j = 0; j < tempNumber.GetSize(); j++)
			res[i + j] += m_number[i] * tempNumber[j];
		res.EditOverflowDigits();
	}

	res.removeInsignificant0();

	return res;
}

LongAryth LongAryth::operator-(const LongAryth &number)
{
    LongAryth tempNumber(number);

	if (*this <= number)
		return LongAryth(0);

	LongAryth res = *this;
	for (size_t i = 0; i < tempNumber.GetSize(); i++)
	{
		if (res[i] < tempNumber[i])
		{
			res[i] += 10;
			size_t j;
			for (j = i + 1; res[j] == 0; j++)
				res[j] = 9;
			res[j] -= 1;
		}
		res[i] -= tempNumber[i];
	}

	res.removeInsignificant0();
	return res;
}

LongAryth LongAryth::operator/(const LongAryth &number)
{
    for 
}

bool LongAryth::operator==(const LongAryth &number) const
{
	return std::equal(begin(), end(), number.begin(), number.end());
}

bool LongAryth::operator!=(const LongAryth &number) const
{
	return !(*this == number);
}

bool LongAryth::operator<(const LongAryth &number) const
{
    LongAryth tempNumber(number);

	size_t i = tempNumber.GetSize();

	if (GetSize() < i)
		return true;
	if (GetSize() > i)
		return false;

	while (i)
	{
		i--;
		if (m_number[i] < tempNumber[i])
			return true;
		if (m_number[i] > tempNumber[i])
			return false;
	}

	return false;
}

bool LongAryth::operator<=(const LongAryth &number) const 
{
	return (*this) == number || (*this) < number;
}

bool LongAryth::operator>(const LongAryth &number) const
{
	return !((*this) <= number);
}

bool LongAryth::operator>=(const LongAryth &number) const
{
	return !((*this) < number);
}

std::ostream &operator<<(std::ostream &os, LongAryth &number)
{
	size_t i = number.GetSize();
	while (i)
	{
		i--;
		os << number[i];
	}
	return os;
}