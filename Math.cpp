#include "BigDecimal.h"


BigDecimal scale(BigDecimal a, int n=15,int round=0)
{
	int i, j, s = a.getString().length();
	for (i = 0; i < s; i++)
	{
		if (a.getString().charAt(i) == '.') break;
	}

	for (j = 0; j < s - i - n - 2; j++)
	{
		a.getString().pop_back();
	}

	if (j == s - i - n - 2)
	{
		if (round == 1)
		{
			a.getString().pop_back();
			if (a.getString().back() == '.')
			{
				a.getString().pop_back();
			}
			a.getString().back()++;

		}
		else if (round == -1)
		{
			a.getString().pop_back();
			if (a.getString().back() == '.')
			{
				a.getString().pop_back();
			}

		}

		else if (round == 0)
		{
			if (a.back() > '4')
			{
				if (a.getString().charAt(a.getString().length() - 2) == '.')
				{
					a.getString().pop_back();
					a.getString().pop_back();
					a.getString().back()++;
				}
				else if (a.digitAt(a.getString().length() - 2) < 9)
				{
					a.getString().pop_back();
					a.getString().back()++;
				}

			}
			else
			{
				a.getString().pop_back();
			}
		}

	}

	return a.trim();
}
BigDecimal ceil(BigDecimal a)
{
	return scale(a, 0, 1);
}
BigDecimal floor(BigDecimal a)
{
	return scale(a, 0, -1);
}
BigDecimal round(BigDecimal a)
{
	return scale(a, 0);
}

BigDecimal exponent(BigDecimal a)
{
	a.trim();

	BigDecimal i, Result = "0", n = "40", P = "1", F = "1";
	for (i = "0"; i<=n; i++)
	{
		if (i > "0")
		{
			P = P * a;
			F = F * i;
		}
		Result = Result + (P / F);
	}
	return Result;
}

BigDecimal BigDecimal::root(BigDecimal x)
{

	this->trim();
	x.trim();
	if (x.getString().empty()) return *this;
	BigDecimal l = "0", r = *this, m = "0";
	if (*this<="1") r = "1";


	while (r.sub(l) > ".00000001")
	{
		BigDecimal temp = (l.add(r)).div("2");
		if (m==temp)
		{
			break;
		}
		m = temp;
		(m.power(x) > *this) ? r = m : l = m;
		// cout << m << endl;
	}

	return m.trim();
}
BigDecimal BigDecimal::power(BigDecimal a)
{
	this->trim();
	a.trim();
	if (a == "0") return "1";
	else if(a == "1") return *this;

	BigDecimal c = "1";

	while (a > "0")
	{
		a=a.sub("1");
		c=c.mul(*this);
	}

	return c;
}

BigDecimal GCD(BigDecimal a,BigDecimal b)
{
    while(a>"0")
     {
        BigDecimal c=a;
        a=b.mod(a);
        b=c;
     }
     return b;
}

BigDecimal LCM(BigDecimal a,BigDecimal b)
{
	 return (a.mul(b)).div(GCD(a,b));
}

BigDecimal BigDecimal::pow(BigDecimal p)
{
	BigDecimal n = *this;

	n.trim();
	p.trim();

	bool inverse = false;

	if (p.getString().front() == '-')
	{
		inverse = true;
		p.getString().pop_front();
	}

	Fraction Num = p.fraction();

	BigDecimal result = this->power(Num.numerator);

	if (Num.denominator > "1") {
		result = result.root(Num.denominator);
	}
	
	if (inverse)
	{
		result = "1" / result;
	}
	return result;
}

BigDecimal BigDecimal::factorial()
{
	this->trim();
	BigDecimal i, fact = "1";
	for (i = "2"; i<=*this;)
	{
		fact = fact.mul(i);
		i = i.add("1");
	}
	return fact;
}

BigDecimal BigDecimal::NPR(BigDecimal r)
{
	BigDecimal s="1",i=((*this-r)+"1");
	while(i<=*this)
	{
		s=(s*i);
		i=(i+"1");
	}
	return s;
}

BigDecimal BigDecimal::NCR(BigDecimal r)
{
	BigDecimal s="1",i="1"; 
	if((r>*this-r)) r=(*this-r);

	while((i<=r))
	{	
		s=(s*((*this-r)+i));
		s=(s/i); 
		i=(i+"1");
	}

	return s;
}

BigDecimal abs(BigDecimal a)
{
	if (a.getSign() == '-') a.getString().pop_front();
	return a;
}