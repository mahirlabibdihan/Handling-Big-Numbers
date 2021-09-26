#include "BigDecimal.h"
BigDecimal BigDecimal::mul(BigDecimal b)
{
	BigDecimal a = *this;
	a.trim();
	b.trim();

	// Base cases
	if (b == "0" || a == "0") return "0";
	else if (b == "1") return *this;
	else if (a == "1") return b;

	// Negative sign finding
	bool negative = false;
	if (a.isNegative() && b.isNegative())
	{
		a = abs(a); 
		b = abs(b);
	}

	else if (b.isNegative())
	{
		negative = true;
		b = abs(b);
	}

	else if (a.isNegative())
	{
		negative = true;
		a = abs(a);
	}



	BigDecimal num1, num2, multiplication;
	if (b.getString().empty()) b = "0";
	if (a.getString().empty()) a = "0";
	int n = b.getString().length(), m = a.getString().length(), p = 0, q = 0;


	// Removing the floating point
	for (int i = 0; i < n; i++)
	{
		if (!b.isFloatingPoint(i))
		{
			num1.getString().push_back(b.getString().charAt(i));
		}
		else
		{
			p = n - 1 - i;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (!a.isFloatingPoint(i))
		{
			num2.getString().push_back(a.getString().charAt(i));
		}
		else
		{
			q = m - 1 - i;
		}
	}

	num1.reverse();
	num2.reverse();

	n = num1.getString().length();
	m = num2.getString().length();

	// Filling the result with '0'
	for (int i = 0; i < m + n; i++)
	{
		multiplication.getString().push_back('0');
	}


	// Main calculation
	int carry;
	for (int i = 0; i < n; i++)
	{
		carry = 0;
		int temp1 = num1.digitAt(i);
		int j;
		for (j = 0; j < m; j++)
		{
			// cout<<".";
			int temp2 = num2.digitAt(j);

			int temp = temp1 * temp2 + multiplication.digitAt(i + j) + carry;

			multiplication.setDigit(i + j, temp % 10);

			carry = temp / 10;
		}

		if (carry) {
			multiplication.setDigit(i + j, multiplication.digitAt(i + j) + carry);
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
			for (int i = n; i < p + q; i++)
			{
				multiplication.getString().push_back('0');
			}
		}

		multiplication.getString().insert(p + q, '.');
		multiplication.reverse();
		multiplication.trim();
	}

	else
	{
		multiplication.reverse();
	}

	if (!multiplication.getString().empty()) {
		return (negative ? "-" : "") + multiplication.getString();
	}
	else {
		return "0";
	}
}
