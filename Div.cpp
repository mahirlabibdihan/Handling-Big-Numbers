 #include "BigDecimal.h"
Fraction BigDecimal::fraction()
{
	BigDecimal numerator = "",denominator = "1";
	this->trim();

	BigDecimal i, n = DecimalToBigDecimal(this->getString().length());

	for (i = "0"; n > i;)
	{
		if (s[BigDecimalToDecimal(i)] == '.')
		{
			for (BigDecimal i = "1"; i<n.sub(i);)
			{
				denominator.getString().push_back('0');
				i = i.add("1");
			}
		}
		else
		{
			numerator.getString().push_back(s[BigDecimalToDecimal(i)]);
		}

		i = i.add("1");
	}

	while (numerator.front() == 0) numerator.getString().pop_front();
	if (numerator.getString().empty()) numerator = "0";
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
	return { numerator,denominator };
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

	if (this->getString().empty()) return (*this);
	bool negative = false;
	this->trim();
	m.trim();
	if (m<="0") return "∞";


	if (this->getString().front() == '-')
	{
		this->getString().pop_front();
		negative = true;
	}

	BigDecimal temp1 = divDigit(*this, m);

	BigDecimal temp2 = m.mul(temp1);

	BigDecimal temp4 = this->sub(temp2);

	return (negative ? "-" : "") + temp4.getString();
}

BigDecimal BigDecimal::div(BigDecimal a)
{

	// cout<<a<<" "<<b<<endl;
	a.trim();
	this->trim();

	// Base cases
	if (a=="0") return "∞";
	else if(a=="1") return *this;
	else if(*this=="0") return "0";

	// Negative sign finding
	bool negative = false;
	if (a.getString().front() == '-' && this->getString().front() == '-')
	{
		a.getString().pop_front();
		this->getString().pop_front();
	}
	else if (a.getString().front() == '-')
	{
		a.getString().pop_front();
		negative = true;
	}
	else if (this->getString().front() == '-')
	{
		this->getString().pop_front();
		negative = true;
	}


	BigDecimal division;
	BigDecimal num1, num2;

	int i, p = 0, q = 0;

	// Removing floating point
	for (i = 0; i < this->getString().length(); i++)
	{
		if (this->getString().charAt(i) == '.')
		{
			p = this->getString().length() - 1 - i;
		}
		else
		{
			num1.getString().push_back(this->getString().charAt(i));
		}
	}

	for (i = 0; i < a.getString().length(); i++)
	{
		if (a.getString().charAt(i) == '.')
		{
			q = a.getString().length() - 1 - i;
		}
		else
		{
			num2.getString().push_back(a.getString().charAt(i));
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
			temp = temp.mod(num2);
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


		temp = temp.mod(num2);

		if (++i < num1.getString().length())
			temp.getString().push_back(num1.getString().charAt(i));
	}



	division.getString().push_back((temp> "0") ? "." : "");

	for (;i - num1.getString().length() < 11 && temp > "0"; i++)
	{
		temp.getString().push_back('0');
		division.getString().push_back(divDigit(temp, num2).getString());
		temp = temp.mod(num2);
	}

	if (i - num1.getString().length() == 11)
	{
		if (division.back() == division.digitAt(division.getString().length() - 2) && division.back() > 4)
			division.getString().back()++;
	}

	return (negative ? "-" : "") + division.getString();
}
