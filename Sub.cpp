#include "BigDecimal.h"
int SubCarry;
BigDecimal subInt(BigDecimal a, BigDecimal b)
{
	BigDecimal substraction;
	int i, n = a.length(), m = b.length();

	a.reverse();
	b.reverse();


	int p = max(m, n);

	for (i = 0; i < p; i++)
	{
		int temp, temp1, temp2;

		if (i > n - 1)
		{
			temp1 = 0;
		}
		else
		{
			temp1 = a[i] - 48;
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b[i] - 48;
		}

		temp = temp1 - temp2 + 10 * (SubCarry + temp2 > temp1) - SubCarry;
		SubCarry = (SubCarry + temp2 > temp1);

		substraction += temp + 48;
	}

	substraction.reverse();
	return substraction;
}

BigDecimal subFrac(BigDecimal a, BigDecimal b)
{
	BigDecimal substraction;
	int i, n = a.length(), m = b.length();

	int p = max(m, n);

	for (i = p - 1; i > -1; i--)
	{
		int temp, temp1, temp2;
		if (i > n - 1)
		{
			temp1 = 0;
		}
		else
		{
			temp1 = a[i] - 48;
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b[i] - 48;
		}

		temp = temp1 - temp2 + 10 * (SubCarry + temp2 > temp1) - SubCarry;
		SubCarry = (SubCarry + temp2 > temp1);

		substraction += temp + 48;
	}

	substraction.reverse();

	return (substraction.length() > 0 ? "." : "") + substraction;
}

BigDecimal BigDecimal::sub(BigDecimal num)
{
	this->trim();
	num.trim();
	if (this->charAt(0) == '-' && num.charAt(0) == '-')
	{
		swap(*this, num);
	}
	else if (this->charAt(0) == '-')
	{
		return this->add("-" + num);
	}
	else if (num.charAt(0) == '-') return this->add(num.pop_front());
	BigDecimal Num1Int, Num1Frac, Num2Int, Num2Frac;
	int i, n = this->length(), m = num.length();
	bool Negative = false;

	for (i = 0; i < n & this->charAt(i) != '.'; i++)
	{
		Num1Int += this->charAt(i);
	}

	for (i++; i < n; i++)
	{
		Num1Frac += this->charAt(i);
	}

	for (i = 0; i < m & num.charAt(i) != '.'; i++)
	{
		Num2Int += num.charAt(i);
	}

	for (i++; i < m; i++)
	{
		Num2Frac += num.charAt(i);
	}

	if (Num1Int.length() == 0) Num1Int = "0";
	if (Num2Int.length() == 0) Num2Int = "0";

	BigDecimal SubFrac, SubInt;

	if (*this<num)
	{
		SubFrac = subFrac(Num2Frac, Num1Frac);
		SubInt = subInt(Num2Int, Num1Int);
		Negative = true;
	}
	else
	{
		SubFrac = subFrac(Num1Frac, Num2Frac);
		SubInt = subInt(Num1Int, Num2Int);
	}

	if (SubInt.length())
		while (SubInt[0] == '0')
		{
			SubInt.pop_front();
		}

	if (SubFrac.length())
	{
		while (SubFrac.back() == '0')
		{
			SubFrac.pop_back();
		}
		if (SubFrac.back() == '.')
		{
			SubFrac.pop_back();
		}
	}
	SubCarry = 0;
	BigDecimal Subion = (Negative ? "-" : "") + SubInt + SubFrac;
	if (Subion.length()) return Subion;
	return "0";
}