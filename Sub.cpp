#include "BigDecimal.h"

BigDecimal subInt(BigDecimal a, BigDecimal b,int &carry)
{
	BigDecimal substraction;
	int i, n = a.getString().length(), m = b.getString().length();

	a.reverse();
	b.reverse();

	int p = max(m, n);

	for (i = 0; i < p; i++)
	{
		int temp, temp1, temp2;

		temp1 = a.digitAt(i);

		temp2 = b.digitAt(i);

		// Main Calculation with carry
		if (carry + temp2 > temp1) {
			temp = (temp1 + 10) - (temp2 + carry);
			carry = 1;
		} 
		else {
			temp = temp1 - (temp2 + carry);
			carry = 0;
		}

		substraction.getString().push_back(temp + '0');
	}

	substraction.reverse();
	return substraction.trim();
}

BigDecimal subFrac(BigDecimal a, BigDecimal b,int &carry)
{
	BigDecimal substraction;
	int i, n = a.getString().length(), m = b.getString().length();

	int p = max(m, n);

	for (i = p - 1; i > -1; i--)
	{
		int temp, temp1, temp2;
		
		temp1 = a.digitAt(i);

		temp2 = b.digitAt(i);

		// Main Calculation with carry
		if (carry + temp2 > temp1) {
			temp = (temp1 + 10) - (temp2 + carry);
			carry = 1;
		} 
		else {
			temp = temp1 - (temp2 + carry);
			carry = 0;
		}

		substraction.getString().push_back(temp + '0');
	}

	substraction.reverse();

	substraction.getString().push_front('.');

	return substraction.trim();
}

BigDecimal BigDecimal::sub(BigDecimal b)
{
	BigDecimal a = *this;
	a.trim();
	b.trim();
	if (a.isNegative() && b.isNegative())
	{
		swap(a, b);
	}
	else if (a.isNegative())
	{
		return a.add("-" + b.getString());
	}
	else if (b.isNegative()) {
		return a.add(abs(b));
	}
	BigDecimal Num1Int, Num1Frac, Num2Int, Num2Frac;
	int i, n = a.getString().length(), m = b.getString().length();
	bool negative = false;

	for (i = 0; i < n ; i++)
	{
		if (a.isFloatingPoint(i)) break;
		Num1Int.getString().push_back(a.getString().charAt(i));
	}

	for (i++; i < n; i++)
	{
		Num1Frac.getString().push_back(a.getString().charAt(i));
	}

	for (i = 0; i < m ; i++)
	{
		if (b.isFloatingPoint(i)) break;
		Num2Int.getString().push_back(b.getString().charAt(i));
	}

	for (i++; i < m; i++)
	{
		Num2Frac.getString().push_back(b.getString().charAt(i));
	}

	if (Num1Int.getString().empty()) Num1Int = "0";
	if (Num2Int.getString().empty()) Num2Int = "0";

	BigDecimal SubFrac, SubInt;

	int carry=0;
	if (a < b)
	{
		SubFrac = subFrac(Num2Frac, Num1Frac,carry);
		SubInt = subInt(Num2Int, Num1Int,carry);
		negative = true;
	}
	else
	{
		SubFrac = subFrac(Num1Frac, Num2Frac,carry);
		SubInt = subInt(Num1Int, Num2Int,carry);
	}

	return (negative ? "-" : "") + (SubInt > "" ? SubInt.getString() : "0") + (SubFrac > "" ? SubFrac.getString() : "");
}