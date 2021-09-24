#include "BigDecimal.h"
bool BigDecimal::operator> (BigDecimal a)
{
	// cout<<*this<<">"<<a<<"="<<(this->compareTo(a))<<endl;
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
bool BigDecimal::operator!=(BigDecimal a)
{
	return this->compareTo(a) != 0;
}

bool BigDecimal::operator<=(BigDecimal a)
{
	return this->compareTo(a) <= 0;
}
bool BigDecimal::operator>=(BigDecimal a)
{
	return this->compareTo(a) >= 0;
}
BigDecimal operator/(const char* str,BigDecimal b){
	return BigDecimal(str) / b;
}
BigDecimal operator-(const char* str,BigDecimal b){
	return BigDecimal(str) - b;
}
BigDecimal::BigDecimal(string str)
{
	this->s = str;
}
BigDecimal::BigDecimal(const char *str)
{
	this->s =  str;
}
BigDecimal::BigDecimal(const BigDecimal &bd)
{
	this->s =  bd.s;
}
BigDecimal::BigDecimal(String bd)
{
	this->s = bd.get();
}

unsigned long long BigDecimal::toInt()
{
	this->trim();
	unsigned long long Decimal = 0;
	int n = this->getString().length(), i;
	for (i = 0; i < n; i++)
	{
		Decimal *= 10;
		Decimal += s[i] - '0';
	}
	return Decimal;
}

istream& operator>>(istream& in, BigDecimal &str){
	in >> str.s;
	return in;
}
ostream& operator<<(ostream& out, BigDecimal str){
	out<<str.s;
	return out;
}

