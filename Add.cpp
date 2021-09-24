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
int addCarry;


BigDecimal addInt(BigDecimal a, BigDecimal b)
{
	BigDecimal addition;

	// For the Int part addition will be done between reversed numbers
	a.getString().reverse();
	b.getString().reverse();

	int i, n = a.getString().length(), m = b.getString().length();
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

		// Main calculation with carry
		temp = temp1 + temp2 + addCarry;
		addCarry = temp / 10;
		addition.getString().push_back((temp % 10) + '0');
	}


	while (addCarry>0) {
		addition.getString().push_back(addCarry%10 + '0');
		addCarry/=10;
	}
	addition.getString().reverse();
	return addition;
}

BigDecimal addFrac(BigDecimal a, BigDecimal b)
{
	BigDecimal addition;

	// cout<<a<<"+"<<b<<endl;
	int i, n = a.getString().length(), m = b.getString().length();
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

		// Main calculation with carry
		temp = temp1 + temp2 + addCarry;
		addCarry = temp / 10;
		addition.getString().push_back((temp % 10) + '0');
		// cout<<addition<<endl;
	}

	addition.getString().reverse();
	// cout<<"->"<<addition<<endl;
	return (addition.getString().length() > 0 ? "." : "") + addition.getString();
}


BigDecimal BigDecimal::add(BigDecimal num)
{

	// cout << *this <<" "<<num<<endl;
	addCarry = 0;
	this->trim();
	num.trim();

	bool negative = false;
	if (this->getString().front() == '-' && num.getString().front() == '-')
	{
		negative = true;
		this->getString().pop_front();
		num.getString().pop_front();
	}
	else if (this->getString().front() == '-') return num.sub(this->getString().pop_front());
	else if (num.getString().front() == '-') return this->sub(num.getString().pop_front());


	BigDecimal num1Int, num1Frac, num2Int, num2Frac;

	int i, n = this->getString().length(), m = num.getString().length();


	// Dividing num1 to Int and Frac part
	for (i = 0; i < n && this->getString().charAt(i) != '.'; i++)
	{
		num1Int.getString().push_back(this->s[i]);
	}

	for (i++; i < n; i++)
	{
		num1Frac.getString().push_back(this->s[i]);
	}

	// Dividing num2 to Int and Frac part
	for (i = 0; i < m & num.getString().charAt(i) != '.'; i++)
	{
		num2Int.getString().push_back(num.getString().charAt(i));
	}

	for (i++; i < m; i++)
	{
		num2Frac.getString().push_back(num.getString().charAt(i));
	}

		// cout<<"->"<<num2Frac<<endl;
		// cout<<(num2Frac > "")<<endl;
		// cout<<"->"<<num2Frac<<endl;

	// Adding frac part of two numbers
	BigDecimal SumFrac = addFrac((num1Frac > "" ? num1Frac : "0"), (num2Frac > "" ? num2Frac : "0"));

	
		
	// Addinf Int part of two numbers
	BigDecimal SumInt = addInt((num1Int > "" ? num1Int : "0"), (num2Int > "" ? num2Int : "0"));

	
	//cout<<(SumFrac>"")<<endl;
	// Removing leading zeros
	SumInt.trim();
	SumFrac.trim();

	return (negative ? "-" : "") + (SumInt>""? SumInt.getString():"0") + (SumFrac>""? SumFrac.getString():"");
}