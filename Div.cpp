#include "BigDecimal.h"
/*pair<BigDecimal,BigDecimal> Fraction(BigDecimal s)
{
	BigDecimal WholeNum = "",DecNum = "1";
	s.trim();
	// cout<<s<<endl;
	BigDecimal i, n = DecimalToBigDecimal(s.length());
	// cout<<" "<<s<<endl;
	for (i = "0"; n > i;)
	{
		if (s[BigDecimalToDecimal(i)] == '.')
		{
			for (BigDecimal i = "1"; i<sub(n, i);)
			{
				DecNum += '0';
				i = add(i, "1");
			}
			// cout<<"#####"<<division<<endl;
		}
		else
		{
			WholeNum += s[BigDecimalToDecimal(i)];
		}

		i = add(i, "1");
	}

	// cout<<Num<<" "<<division<<endl;
	while (WholeNum[0] == '0') WholeNum.pop_front();
	if (WholeNum.length() == 0) WholeNum = "0";
	BigDecimal temp = WholeNum;

	// cout<<endl<<Num<<" "<<Compare(Mul("2","2"), temp)<<endl;
	for (i = "2"; i<=WholeNum;)
	{
		// cout<<i<<endl;
		if (Mod(WholeNum, i) == "0" && Mod(DecNum, i) == "0")
		{
			WholeNum = WholeNum.div(i);
			DecNum = DecNum.division(i);
			// cout<<Mod(division, i)<<endl;
		}
		i = add(i, "1");
		// cout<<" -"<<division<<endl;
	}
	return pair<BigDecimal,BigDecimal>(WholeNum,DecNum); 
}*/
BigDecimal divDigit(BigDecimal a, BigDecimal b)
{
	a.trim();
	b.trim();
	if (b=="0") return "∞";
	BigDecimal i, j = "0";
	for (i = "0"; j.compareTo(a)<1;)
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
	if (this->length() == 0) return (*this);
	bool negative = false;
	this->trim();
	m.trim();
	if (m.compareTo("0") < 1) return "∞";


	if (this->charAt(0) == '-')
	{
		this->pop_front();
		negative = true;
	}
	BigDecimal temp1 = divDigit(*this, m);
	//cout<<temp1<<endl;
	BigDecimal temp2 = m.mul(temp1);
	BigDecimal temp4 = this->sub(temp2);
	//cout<<Number<<" "<<Mod<<" "<<temp1<<" "<<temp2<<" "<<temp4<<endl;
	return (negative ? "-" : "") + temp4;
}

BigDecimal BigDecimal::div(BigDecimal a)
{
	// cout<<a<<" "<<b<<endl;
	a.trim();
	this->trim();

	if (a=="0") return "∞";
	//cout<<a<<" "<<b<<endl;
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
		// cout<<"######"<<endl;
		temp = num1 + "0";
		division = ".";


		// cout<<division<<" "<<temp<<endl;

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
		//cout<<" -"<<division<<endl;
		temp = temp.mod(num2);

		if (++i < num1.length())
			temp += num1[i];
	}

	//cout<<division<<" "<<temp<<endl;


	division += (temp> "0") ? "." : "";

	for (; (i - num1.length() < 11 && temp>"0"); i++)
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
