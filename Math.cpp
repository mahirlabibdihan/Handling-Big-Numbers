#include "BigDecimal.h"


BigDecimal scale(BigDecimal a, int n = 15, int round = 0)
{
	int i, j, s = a.getString().length();
	for (i = 0; i < s; i++)
	{
		if (a.isDecimalPoint(i)) break;
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
	for (i = "0"; i <= n; i++)
	{
		if (i > "0")
		{
			P *= a;
			F *= i;
		}
		Result = Result + (P / F);
	}
	return Result;
}

BigDecimal BigDecimal::root(BigDecimal b)
{
	BigDecimal a = *this;
	a.trim();
	b.trim();
	if (b.getString().empty()) return a;
	BigDecimal l = "0", r = a, m = "0";
	if (a <= "1") r = "1";


	while (r - l > ".00000001")
	{
		BigDecimal temp = (l + r) / "2";
		if (m == temp)
		{
			break;
		}
		m = temp;
		(m.power(b) > a) ? r = m : l = m;
		// cout << m << endl;
	}

	return m.trim();
}
BigDecimal BigDecimal::power(BigDecimal p)
{
	BigDecimal n = *this;
	n.trim();
	p.trim();
	if (p == "0") return "1";
	else if (p == "1") return n;

	BigDecimal c = "1";

	while (p > "0")
	{
		p -= "1";
		c *= n;
	}

	return c;
}

BigDecimal GCD(BigDecimal a, BigDecimal b)
{
	while (a > "0")
	{
		BigDecimal c = a;
		a = b % a;
		b = c;
	}
	return b;
}

BigDecimal LCM(BigDecimal a, BigDecimal b)
{
	return (a * b) / GCD(a, b);
}

BigDecimal BigDecimal::pow(BigDecimal p)
{
	BigDecimal n = *this;

	n.trim();
	p.trim();

	bool inverse = false;

	if (p.isNegative())
	{
		inverse = true;
		p = abs(p);
	}

	Fraction Num = p.fraction();

	BigDecimal result = n.power(Num.numerator);

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
	BigDecimal n = *this;
	n.trim();
	BigDecimal i, fact = "1";
	for (i = "2"; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}

BigDecimal BigDecimal::NPR(BigDecimal r)
{
	BigDecimal n = *this;
	n.trim();
	r.trim();
	BigDecimal s = "1", i;
	for (i = (n - r) + "1"; i <= n; i++)
	{
		s *= i;
	}
	return s;
}

BigDecimal BigDecimal::NCR(BigDecimal r)
{
	BigDecimal n = *this;
	n.trim();
	r.trim();
	BigDecimal s = "1", i;
	if (r > n - r) r = n - r;

	for (i = "1"; i <= r; i++)
	{
		s *= ((n - r) + i);
		s /= i;
	}

	return s;
}

BigDecimal abs(BigDecimal a)
{
	if (a.getSign() == '-') a.getString().pop_front();
	return a;
}