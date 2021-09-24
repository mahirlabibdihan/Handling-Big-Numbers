#include "BigDecimal.h"

BigDecimal scale(BigDecimal a, int n=15,int round=0)
{
	int i, j, s = a.length();
	for (i = 0; i < s; i++)
	{
		if (a[i] == '.') break;
	}

	for (j = 0; j < s - i - n - 2; j++)
	{
		a.pop_back();
	}

	if (j == s - i - n - 2)
	{
		if (round == 1)
		{
			a.pop_back();
			if (a.back() == '.')
			{
				a.pop_back();
			}
			a.back()++;

		}
		else if (round == -1)
		{
			a.pop_back();
			if (a.back() == '.')
			{
				a.pop_back();
			}

		}

		else if (round == 0)
		{
			if (a.back() > '4')
			{
				if (a[a.length() - 2] == '.')
				{
					a.pop_back();
					a.pop_back();
					a.back()++;
				}
				else if (a[a.length() - 2] < '9')
				{
					a.pop_back();
					a.back()++;
				}

			}
			else
			{
				a.pop_back();
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

/*BigDecimal exponent(BigDecimal a)
{
	a.trim();

	BigDecimal i, Result = "0", n = "40", P = "1", F = "1";
	for (i = "0"; Compare(i, n) < 1;)
	{
		if (Compare(i, "0") > 0)
		{
			P = P.mul(a);
			F = F.mul(i);
		}
		Result = Result.add(P.div(F));
		i = i.add("1");
	}
	return Result;
}*/

BigDecimal BigDecimal::root(BigDecimal x)
{

	this->trim();
	x.trim();
	if (x.empty()) return *this;
	BigDecimal l = "0", r = *this, m = "0";
	if (*this<="1") r = "1";


	while (r.sub(l) > ".000000000001")
	{
		BigDecimal temp = (l.add(r)).div("2");
		if (m==temp)
		{
			break;
		}
		m = temp;
		(m.power(x) > *this) ? r = m : l = m;
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
	bool negative = false;

	if (a[0] == '-')
	{
		negative = true;
		a.pop_front();
	}

	while (a > "0")
	{
		a=a.sub("1");
		c=c.mul(*this);
	}

	if (negative)
	{
		c = BigDecimal("1").div(c);
	}
	return c;
}

/*BigDecimal GCD(BigDecimal a,BigDecimal b)
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
}*/


BigDecimal BigDecimal::pow(BigDecimal p)
{
	this->trim();
	p.trim();
	pair<BigDecimal,BigDecimal> Num(p.fraction());
	BigDecimal temp = this->power(Num.first);

	if (Num.second > "1") return temp.root(Num.second);
	return temp;
}

BigDecimal BigDecimal::factorial()
{
	this->trim();
	BigDecimal i, fact = "1";
	for (i = "2"; i.compareTo(*this) < 1;)
	{
		fact = fact.mul(i);
		i = i.add("1");
	}
	return fact;
}

/*BigDecimal NPR(BigDecimal n,BigDecimal r)
{
	BigDecimal s="1",i=Add(Sub(n,r),"1");
	while(Compare(i,n)<1)
	{
		s=Mul(s,i);
		i=Add(i,"1");
	}
	return s;
}

BigDecimal NCR(BigDecimal n,BigDecimal r)
{
	BigDecimal s="1",i="1"; 
	if(Compare(r,Sub(n,r))>0) r=Sub(n,r);

	while(Compare(i,r)<1)
	{	
		s=Mul(s,Add(Sub(n,r),i));
		s=Div(s,i); 
		i=Add(i,"1");
	}

	return s;
}

BigDecimal Abs(BigDecimal a, BigDecimal b)
{
	if (Compare(a, b) > -1) return Sub(a, b);
	return Sub(b, a);
}*/