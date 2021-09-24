#include "BigDecimal.h"
pair<BigDecimal,BigDecimal> BigDecimal::fraction()
{
	BigDecimal numerator = "",denominator = "1";
	this->trim();

	BigDecimal i, n = DecimalToBigDecimal(this->length());

	for (i = "0"; n > i;)
	{
		if (s[BigDecimalToDecimal(i)] == '.')
		{
			for (BigDecimal i = "1"; i<n.sub(i);)
			{
				denominator += '0';
				i = i.add("1");
			}
		}
		else
		{
			numerator += s[BigDecimalToDecimal(i)];
		}

		i = i.add("1");
	}

	while (numerator[0] == '0') numerator.pop_front();
	if (numerator.empty()) numerator = "0";
	BigDecimal temp = numerator;

	for (i = "2"; i<=numerator;)
	{
		if (numerator.mod(i) == "0" && denominator.mod(i) == "0")
		{
			numerator = numerator.div(i);
			denominator = denominator.div(i);
		}
		i = i.add("1");
	}
	return pair<BigDecimal,BigDecimal>(numerator,denominator); 
}
BigDecimal divDigit(BigDecimal a, BigDecimal b)
{	
	// cout<<a<<" "<<b<<endl;
	a.trim();
	b.trim();
	if (b=="0") return "∞";
	BigDecimal i, j = "0";
	for (i = "0"; j<=a;)
	{
		j = j.add(b);
		i = i.add("1");
	}
	return i.sub("1");
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

BigDecimal BigDecimal::mod(BigDecimal m)
{

	if (this->empty()) return (*this);
	bool negative = false;
	this->trim();
	m.trim();
	if (m<="0") return "∞";


	if (this->charAt(0) == '-')
	{
		this->pop_front();
		negative = true;
	}

	BigDecimal temp1 = divDigit(*this, m);

	BigDecimal temp2 = m.mul(temp1);

	BigDecimal temp4 = this->sub(temp2);

	return (negative ? "-" : "") + temp4;
}

BigDecimal BigDecimal::div(BigDecimal a)
{

	// cout<<a<<" "<<b<<endl;
	a.trim();
	this->trim();

	// Base cases
	if (a=="0") return "∞";
	else if(a=="1") return *this;

	// Negative sign finding
	bool negative = false;
	if (a.charAt(0) == '-' && this->charAt(0) == '-')
	{
		a.pop_front();
		this->pop_front();
	}
	else if (a.charAt(0) == '-')
	{
		a.pop_front();
		negative = true;
	}
	else if (this->charAt(0) == '-')
	{
		this->pop_front();
		negative = true;
	}

	BigDecimal division;
	BigDecimal num1, num2;

	int i, p = 0, q = 0;

	// Removing floating point
	for (i = 0; i < this->length(); i++)
	{
		if (this->charAt(i) == '.')
		{
			p = this->length() - 1 - i;
		}
		else
		{
			num1 += this->charAt(i);
		}
	}

	for (i = 0; i < a.length(); i++)
	{
		if (a[i] == '.')
		{
			q = a.length() - 1 - i;
		}
		else
		{
			num2 += a[i];
		}
	}

	// cout<<num1<<" "<<num2<<endl;


	if (p > q)
	{
		for (i = 0; i < p - q; i++)
		{
			num2 += '0';
		}
	}

	else if (p < q)
	{
		for (i = 0; i < q - p; i++)
		{
			num1 += '0';
		}
	}

	// cout<<num1<<" "<<num2<<" "<<endl;

	BigDecimal temp;

	if (num2>num1)
	{
		temp = num1 + "0";
		division = ".";

		for (i = 0; i < 15 && temp>"0"; i++)
		{
			division += divDigit(temp, num2);
			temp = temp.mod(num2);
			temp += '0';
			// cout<<"-"<<division<<endl;
		}

		return (negative ? "-" : "") + division;
	}

	for (i = -1; num2>temp;)
	{
		temp += num1[++i];
	}


	for (; (i < num1.length());)
	{
		division += divDigit(temp, num2);


		temp = temp.mod(num2);

		if (++i < num1.length())
			temp += num1[i];
	}


	division += (temp> "0") ? "." : "";

	for (;i - num1.length() < 11 && temp > "0"; i++)
	{
		temp += '0';
		division += divDigit(temp, num2);
		temp = temp.mod(num2);
	}

	if (i - num1.length() == 11)
	{
		if (division.back() == division[division.length() - 2] && division.back() > '4')
			division.back()++;
	}

	return (negative ? "-" : "") + division;
}
