#include "BigDecimal.h"
int SubCarry;
BigDecimal subInt(BigDecimal a, BigDecimal b)
{
	BigDecimal substraction;
	int i, n = a.getString().length(), m = b.getString().length();

	a.getString().reverse();
	b.getString().reverse();

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
			temp1 = a.digitAt(i);
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b.digitAt(i);
		}

		// Main Calculation with carry
		if (SubCarry + temp2 > temp1) {
			temp = (temp1 + 10) - (temp2 + SubCarry);
			SubCarry = 1;
		} 
		else {
			temp = temp1 - (temp2 + SubCarry);
			SubCarry = 0;
		}

		substraction.getString().push_back(temp + '0');
	}

	substraction.getString().reverse();
	return substraction;
}

BigDecimal subFrac(BigDecimal a, BigDecimal b)
{
	BigDecimal substraction;
	int i, n = a.getString().length(), m = b.getString().length();

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
			temp1 = a.digitAt(i);
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b.digitAt(i);
		}

		// Main Calculation with carry
		if (SubCarry + temp2 > temp1) {
			temp = (temp1 + 10) - (temp2 + SubCarry);
			SubCarry = 1;
		} 
		else {
			temp = temp1 - (temp2 + SubCarry);
			SubCarry = 0;
		}

		substraction.getString().push_back(temp + '0');
	}

	substraction.getString().reverse();

	return (substraction.getString().length() > 0 ? "." : "") + substraction.getString();
}

BigDecimal BigDecimal::sub(BigDecimal num)
{
	this->trim();
	num.trim();
	if (this->getString().charAt(0) == '-' && num.getString().charAt(0) == '-')
	{
		swap(*this, num);
	}
	else if (this->getString().charAt(0) == '-')
	{
		return this->add("-" + num.getString());
	}
	else if (num.getString().charAt(0) == '-') return this->add(num.getString().pop_front());
	BigDecimal Num1Int, Num1Frac, Num2Int, Num2Frac;
	int i, n = this->getString().length(), m = num.getString().length();
	bool Negative = false;

	for (i = 0; i < n & this->getString().charAt(i) != '.'; i++)
	{
		Num1Int.getString().push_back(this->getString().charAt(i));
	}

	for (i++; i < n; i++)
	{
		Num1Frac.getString().push_back(this->getString().charAt(i));
	}

	for (i = 0; i < m & num.getString().charAt(i) != '.'; i++)
	{
		Num2Int.getString().push_back(num.getString().charAt(i));
	}

	for (i++; i < m; i++)
	{
		Num2Frac.getString().push_back(num.getString().charAt(i));
	}

	if (Num1Int.getString().empty()) Num1Int = "0";
	if (Num2Int.getString().empty()) Num2Int = "0";

	BigDecimal SubFrac, SubInt;

	if (*this < num)
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

	// cout<<SubInt<<" "<<SubInt[0]<<endl;

	while (!SubInt.getString().empty()&& SubInt.front() == 0)
	{
		// cout<<SubInt<<" "<<SubInt[0]<<endl;
		SubInt.getString().pop_front();
	}
	// cout<<SubInt<<" "<<SubInt[0]<<endl;

	if (SubFrac.getString().length())
	{
		while (SubFrac.back() == 0)
		{
			SubFrac.getString().pop_back();
		}
		if (SubFrac.getString().back() == '.')
		{
			SubFrac.getString().pop_back();
		}
	}
	SubCarry = 0;
	BigDecimal substraction = (Negative ? "-" : "") + SubInt.getString() + SubFrac.getString();

	// cout<<*this<<"-"<<num<<"="<<substraction<<endl;
	if (substraction.getString().length()) return substraction;
	return "0";
}