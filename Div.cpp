 #include "BigDecimal.h"
Fraction BigDecimal::fraction()
{
	BigDecimal numerator = "",denominator = "1";
	this->trim();

	BigDecimal i,j, n = DecimalToBigDecimal(this->getString().length());

	for (i = "0"; n > i;i++)
	{
		if (s[BigDecimalToDecimal(i)] == '.')
		{
			for (BigDecimal j = "1"; j<n - i;j++)
			{
				denominator.getString().push_back('0');
			}
		}
		else
		{
			numerator.getString().push_back(s[BigDecimalToDecimal(i)]);
		}
	}

	numerator.trim();

	BigDecimal temp = numerator;

	for (i = "2"; i<=numerator;i++)
	{
		if (numerator%i == "0" && denominator%i == "0")
		{
			numerator = numerator/i;
			denominator = denominator/i;
		}
	}
	return { numerator,denominator };
}
BigDecimal divDigit(BigDecimal a, BigDecimal b)
{	
	// cout<<a<<" "<<b<<endl;
	a.trim();
	b.trim();
	if (b=="0") return "∞";
	BigDecimal i, j = "0";
	for (i = "0"; j<=a; i++)
	{
		j = j + b;
	}
	return i - "1";
}
/*BigDecimal Remainder(BigDecimal Rad)
{
	BigDecimal i, j = "1";
	BigDecimal P = "1", F = "1";
	for (i = "1"; j>"0.000000000005";)
	{
		P = mul(P, Rad);
		P = mul(P, Rad);
		F = mul(F, i);
		F = mul(F, add(i, "1"));
		j = div(P, F);
		i = add(i, "2");
	}

	return sub(i, "2");
}*/

BigDecimal BigDecimal::mod(BigDecimal b)
{
	BigDecimal a = *this;
	if (a.getString().empty()) return a;
	bool negative = false;
	a.trim();
	b.trim();
	if (b<="0") return "∞";


	if (a.isNegative())
	{
		a = abs(a);
		negative = true;
	}

	BigDecimal temp1 = divDigit(a , b);

	BigDecimal temp2 = b * temp1;

	BigDecimal temp4 = a - temp2;

	return (negative ? "-" : "") + temp4.getString();
}

BigDecimal BigDecimal::div(BigDecimal b)
{
	BigDecimal a = *this;
	// cout<<a<<" "<<b<<endl;
	b.trim();
	a.trim();

	// Base cases
	if (b=="0") return "∞";
	else if(b=="1") return a;
	else if(a=="0") return "0";

	// Negative sign finding
	bool negative = false;
	if (b.isNegative() && a.isNegative())
	{
		b = abs(b);
		a = abs(a);
	}
	else if (b.isNegative())
	{
		b = abs(b);
		negative = true;
	}
	else if (a.isNegative())
	{
		a = abs(a);
		negative = true;
	}


	BigDecimal division;
	BigDecimal num1, num2;

	int i, p = 0, q = 0;

	// Removing floating point
	for (i = 0; i < a.getString().length(); i++)
	{
		if (a.isFloatingPoint(i))
		{
			p = a.getString().length() - 1 - i;
		}
		else
		{
			num1.getString().push_back(this->getString().charAt(i));
		}
	}

	for (i = 0; i < b.getString().length(); i++)
	{
		if (b.isFloatingPoint(i))
		{
			q = b.getString().length() - 1 - i;
		}
		else
		{
			num2.getString().push_back(b.getString().charAt(i));
		}
	}

	// cout<<num1<<" "<<num2<<endl;


	if (p > q)
	{
		for (i = 0; i < p - q; i++)
		{
			num2.getString().push_back('0');
		}
	}

	else if (p < q)
	{
		for (i = 0; i < q - p; i++)
		{
			num1.getString().push_back('0');
		}
	}

	// cout<<num1<<" "<<(num2>num1)<<" "<<endl;

	BigDecimal temp;

	

	if (num2>num1)
	{
		temp = num1.getString() + "0";
		division = ".";

		for (i = 0; i < 15 && temp>"0"; i++)
		{
			division.getString().push_back(divDigit(temp, num2).getString());
			temp = temp % num2;
			temp.getString().push_back('0');
			// cout<<"-"<<division<<endl;
		}

		return (negative ? "-" : "") + division.getString();
	}


	for (i = -1; num2>temp;)
	{
		temp.getString().push_back(num1.getString().charAt(++i));
	}


	for (; (i < num1.getString().length());)
	{
		division.getString().push_back(divDigit(temp, num2).getString());


		temp = temp % num2;

		if (++i < num1.getString().length())
			temp.getString().push_back(num1.getString().charAt(i));
	}


	division.getString().push_back((temp> "0") ? "." : "");

	for (;i - num1.getString().length() < 11 && temp > "0"; i++)
	{
		temp.getString().push_back('0');
		division.getString().push_back(divDigit(temp, num2).getString());
		temp = temp % num2;
	}

	if (i - num1.getString().length() == 11)
	{
		if (division.back() == division.digitAt(division.getString().length() - 2) && division.back() > 4)
			division.getString().back()++;
	}

	return (negative ? "-" : "") + division.getString();
}
