#include "BigDecimal.h"
bool BigDecimal::operator> (BigDecimal a)
{
	return this->compareTo(a)==1;
}
bool BigDecimal::operator<(BigDecimal a)
{
	return this->compareTo(a) == -1;
}
bool BigDecimal::operator==(BigDecimal a)
{
	return this->compareTo(a) == 0;
}
BigDecimal::BigDecimal(const char *str)
{
	s =  str;
}
BigDecimal::BigDecimal(const BigDecimal &bd)
{
	s =  bd.s;
}
BigDecimal::BigDecimal(String bd)
{
	s = bd.get();
}

unsigned long long BigDecimal::toInt()
{
	this->trim();
	unsigned long long Decimal = 0;
	int n = this->length(), i;
	for (i = 0; i < n; i++)
	{
		Decimal *= 10;
		Decimal += s[i] - '0';
	}
	return Decimal;
}
