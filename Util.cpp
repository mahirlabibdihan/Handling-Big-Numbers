#include "BigDecimal.h"
int BigDecimal::compareTo(BigDecimal num)
{
	this->trim();
	num.trim();
	int i, n = this->length(), m = num.length();
	BigDecimal Num1Int, Num1Frac, Num2Int, Num2Frac;

	for (i = 0; i < n; i++)
	{
		if (s[i] == '.') break;
		Num1Int += s[i];
	}
	for (i++; i < n; i++)
	{
		Num1Frac += s[i];
	}

	for (i = 0; i < m; i++)
	{
		if (num[i] == '.') break;
		Num2Int += num[i];
	}
	for (i++; i < m; i++)
	{
		Num2Frac += num[i];
	}

	if (Num1Int.length() == 0) Num1Int = "0";
	if (Num2Int.length() == 0) Num2Int = "0";
	if (Num1Frac.length() == 0) Num1Frac = "0";
	if (Num2Frac.length() == 0) Num2Frac = "0";
	// cout<<endl<<"->1."<<Num1Int<<" 2."<<Num1Frac<<" 3."<<Num2Int<<" 4."<<Num2Frac<<endl;

	if (Num1Int.front() == '-' && Num2Int.front() != '-') return -1;
	else if (Num1Int.front() != '-' && Num2Int.front() == '-') return 1;

	if (Num1Int.length() > Num2Int.length()) return 1;
	else if (Num1Int.length() == Num2Int.length())
	{
		if (Num1Int.compare(Num2Int) > 0) return 1;
		else if (Num1Int.compare(Num2Int) == 0)
		{
			return Num1Frac.compare(Num2Frac);
		}
		else return -1;
	}
	else return -1;
}

BigDecimal BigDecimal::trim()
{
	if (this->s == "∞") return *this;

	BigDecimal Int, Frac;

	int i, n = this->length();

	
	for (i = 0; i < n; i++)
	{
		if (s[i] == '.') break;
		Int += s[i];
	}
	for (; i < n; i++)
	{
		Frac += s[i];
	}

	if (Int[0] == '-')
	{
		while (Int.length() > 1 && Int[1] == '0')
		{
			Int.erase(1);
		}
	}

	else
	{
		while (Int.length() > 0 && Int.front() == '0')
		{
			Int.pop_front();
		}
	}

	while (Frac.length() > 0 && Frac.back() == '0')
	{
		Frac.pop_back();
	}

	if (Frac.length() > 0 && Frac.back() == '.')
	{
		Frac.pop_back();
	}

	set(Int + Frac);

	if (length() == 0)
	{
		set("0");
	}

	return *this;
}

unsigned long long BigDecimal::BigDecimalToDecimal(BigDecimal Number)
{
	Number.trim();
	unsigned long long Decimal = 0;
	int n = Number.length(), i;

	for (i = 0; i < n; i++)
	{
		Decimal *= 10;
		Decimal += (Number[i] - '0');
	}

	return Decimal;
}


BigDecimal BigDecimal::DecimalToBigDecimal(unsigned long long Decimal)
{
	BigDecimal Number;
	while (Decimal > 0)
	{
		Number += ('0' + Decimal % 10);
		Decimal /= 10;
	}
	Number.reverse();

	return Number.trim();
}
