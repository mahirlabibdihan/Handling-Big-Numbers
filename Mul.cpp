#include "BigDecimal.h"
BigDecimal BigDecimal::mul(BigDecimal a)
{
	this->trim();
	a.trim();

	// Base cases
	if (a == "0" || (*this) == "0") return "0";
	else if (a == "1") return *this;
	else if (*this == "1") return a;

	// Negative sign finding
	bool negative = false;
	if ( this->getString().front() == '-'  && a.getString().front() == '-')
	{
		this->getString().pop_front();
		a.getString().pop_front();
	}

	else if (a.getString().front() == '-')
	{
		negative = true;
		a.getString().pop_front();
	}

	else if (this->getString().front() == '-')
	{
		negative = true;
		this->getString().pop_front();
	}



	BigDecimal num1, num2, multiplication;
	if (a.getString().length() == 0) a.getString().set("0");
	if (this->getString().length() == 0) this->getString().set("0");
	int i, j, n = a.getString().length(), m = this->getString().length(), p = 0, q = 0;


	// Removing the floating point
	for (i = 0; i < n; i++)
	{
		if (a.getString().charAt(i) != '.')
		{
			num1.getString().push_back(a.getString().charAt(i));
		}
		else
		{
			p = n - 1 - i;
		}
	}

	for (i = 0; i < m; i++)
	{
		if (this->getString().charAt(i) != '.')
		{
			num2.getString().push_back(this->getString().charAt(i));
		}
		else
		{
			q = m - 1 - i;
		}
	}

	num1.getString().reverse();
	num2.getString().reverse();

	n = num1.getString().length();
	m = num2.getString().length();

	// Filling the result with '0'
	for (i = 0; i < m + n ; i++)
	{
		multiplication.getString().push_back('0');
	}


	// Main calculation
	int Carry;
	for (i = 0; i < n; i++)
	{
		Carry = 0;
		int temp1 = num1.digitAt(i);

		for (j = 0; j < m; j++)
		{
			// cout<<".";
			int temp2 = num2.digitAt(j);

			int temp = temp1 * temp2 + multiplication.digitAt(i + j) + Carry;

			multiplication.setDigit(i + j , temp % 10);

			Carry = temp / 10;
		}

		if (Carry) {
			multiplication.setDigit(i + j , multiplication.digitAt(i+j)+Carry);
		}

	}

	// Removing leading zero's
	while (multiplication.getString().length() > 0 && multiplication.back() == 0) {
		multiplication.getString().pop_back();
	}


	// Inserting back the floating point into the result
	n = multiplication.getString().length();
	if (p + q > 0)
	{
		if (p + q > n)
		{
			for (i = n; i < p + q; i++)
			{
				multiplication.getString().push_back('0');
			}
		}

		multiplication.getString().insert(p + q, '.');
		multiplication.getString().reverse();
		multiplication.trim();
	}

	else
	{
		multiplication.getString().reverse();
	}

	if (multiplication.getString().length() > 0) {
		return (negative ? "-" : "") + multiplication.getString();
	}
	else {
		return "0";
	}
}
