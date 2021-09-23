#include "BigDecimal.h"
int addCarry;

BigDecimal addInt(BigDecimal a, BigDecimal b)
{
	BigDecimal addition;

	// For the Int part addition will be done between reversed numbers
	a.reverse();
	b.reverse();

		int i, n = a.length(), m = b.length();
	// Taking larger number first
	if (m > n) {
		swap(a, b);
		swap(n, m);
	}

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

		temp = temp1 + temp2 + addCarry;
		addCarry = temp / 10;
		addition += (temp % 10) + 48;
	}


	while (addCarry>0) {
		addition += addCarry%10 + 48;
		addCarry/=10;
	}
	addition.reverse();
	return addition;
}

BigDecimal addFrac(BigDecimal a, BigDecimal b)
{
	BigDecimal addition;

	int i, n = a.length(), m = b.length();
	// Taking larger number first
	if (m > n) {
		swap(a, b);
		swap(n, m);
	}

	int p = max(m, n);


	for (i = p-1; i > -1; i--)
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

		temp = temp1 + temp2 + addCarry;
		addCarry = temp / 10;
		addition += (temp % 10) + 48;
	}

	addition.reverse();
	return (addition.length() > 0 ? "." : "") + addition;
}


BigDecimal BigDecimal::add(BigDecimal num)
{

	addCarry = 0;
	this->trim();
	num.trim();

	
	bool negative = false;
	if (this->front() == '-' && num.front() == '-')
	{
		negative = true;
		this->pop_front();
		num.pop_front();
	}
	else if (this->front() == '-') return num.sub(this->pop_front());
	else if (num.front() == '-') return this->sub(num.pop_front());



	BigDecimal num1Int, num1Frac, num2Int, num2Frac;

	int i, n = this->length(), m = num.length();

	// Dividing num1 to Int and Frac part
	for (i = 0; i < n && this->charAt(i) != '.'; i++)
	{
		num1Int += this->s[i];
	}

	for (i++; i < n; i++)
	{
		num1Frac += this->s[i];
	}

	// Dividing num2 to Int and Frac part
	for (i = 0; i < m & num[i] != '.'; i++)
	{
		num2Int += num[i];
	}

	for (i++; i < m; i++)
	{
		num2Frac += num[i];
	}


	// Adding frac part of two numbers
	BigDecimal SumFrac = addFrac((num1Frac > "" ? num1Frac : "0"), (num2Frac > "" ? num2Frac : "0"));


	
	// Addinf Int part of two numbers
	BigDecimal SumInt = addInt((num1Int > "" ? num1Int : "0"), (num2Int > "" ? num2Int : "0"));


	// Removing leading zeros
	SumInt.trim();
	SumFrac.trim();

	return (negative ? "-" : "") + (SumInt>""? SumInt:"0") + (SumFrac>""? SumFrac:"");
}