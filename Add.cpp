/*
/*
12345678.433
	2334.23432421

1. Dividing into two parts
12345678		433
	2334		23432421

2.Reverse		2.Swap
87654321		23432421
4332			433
--------		--------
12084321		66732421

3.Reverse		3.Adding dot
12348021		.66732421

4.Add
12348021.66732421

Addition of fractional part needs to be done first.
Because remaining carry of this part will be added to addition of int part.
*/
#include "BigDecimal.h"

BigDecimal addInt(BigDecimal a, BigDecimal b,int &carry)
{
	// For the Int part addition will be done between reversed numbers

	int n = a.getString().length(), m = b.getString().length();
	// Taking larger number first

	a.reverse();
	b.reverse();

	BigDecimal addition;
	int len = max(n, m);
	for (int i = 0; i < len; i++)
	{
		int temp, temp1, temp2;

		temp1 = a.digitAt(i);

		temp2 = b.digitAt(i);

		// Main calculation with carry
		temp = temp1 + temp2 + carry;
		carry = temp / 10;
		addition.getString().push_back((temp % 10) + '0'); // addition = addition * "10";  addition = addition + ((temp % 10) + '0');
	}

	if (carry > 0) {
		addition.getString().push_back(carry % 10 + '0');
	}

	addition.reverse();
	return addition.trim();
}

BigDecimal addFrac(BigDecimal a, BigDecimal b, int &carry)
{
	

	// cout<<a<<"+"<<b<<endl;
	int i, n = a.getString().length(), m = b.getString().length();
	// Taking larger number first

	int len = max(n, m);
	BigDecimal addition;
	for (i = len - 1; i > -1; i--)
	{
		int temp, temp1, temp2;

		temp1 = a.digitAt(i);

		temp2 = b.digitAt(i);
		
		// Main calculation with carry
		temp = temp1 + temp2 + carry;
		carry = temp / 10;
		addition.getString().push_back((temp % 10) + '0');
		// cout<<addition<<endl;
	}

	addition.reverse();

	addition.getString().push_front('.');

	// cout<<"->"<<addition<<endl;
	return addition.trim();
}

BigDecimal BigDecimal::add(BigDecimal b)
{
	BigDecimal a(*this);
	// cout << *this <<" "<<num<<endl;
	int carry = 0;
	a.trim();
	b.trim();

	bool negative = false;
	if (a.isNegative() && b.isNegative())
	{
		negative = true;
		a = abs(a);
		b = abs(b);
	}
	else if (a.isNegative()) {
		return b - abs(a);
	}
	else if (b.isNegative()) {
		return a - abs(b);
	}

	BigDecimal num1Int, num1Frac, num2Int, num2Frac;

	int i, n = a.getString().length(), m = b.getString().length();


	// Dividing num1 to Int and Frac part
	for (i = 0; i < n; i++)
	{
		if (a.isFloatingPoint(i)) break;
		num1Int.getString().push_back(a.getString().charAt(i));
	}

	for (i++; i < n; i++)
	{
		num1Frac.getString().push_back(a.getString().charAt(i));
	}

	// Dividing num2 to Int and Frac part
	for (i = 0; i < m; i++)
	{
		if (b.isFloatingPoint(i)) break;
		num2Int.getString().push_back(b.getString().charAt(i));
	}

	for (i++; i < m; i++)
	{
		num2Frac.getString().push_back(b.getString().charAt(i));
	}

// Adding frac part of two numbers
	BigDecimal sumFrac = addFrac((num1Frac > "" ? num1Frac : "0"), (num2Frac > "" ? num2Frac : "0"),carry);

	// Addinf Int part of two numbers
	BigDecimal sumInt = addInt((num1Int > "" ? num1Int : "0"), (num2Int > "" ? num2Int : "0"),carry);

	return (negative ? "-" : "") + (sumInt > "" ? sumInt.getString() : "0") + (sumFrac > "" ? sumFrac.getString() : "");
}