#include "Mul.h"
string Mul(string a, string b)
{
	a = Trim(a);
	b = Trim(b);
	if (Compare(a, "0") == 0 || Compare(b, "0") == 0) return "0";
	bool Negative = false;
	if (a[0] == '-' && b[0] == '-')
	{
		a.erase(a.begin());
		b.erase(b.begin());
	}

	else if (a[0] == '-')
	{
		Negative = true;
		a.erase(a.begin());
	}

	else if (b[0] == '-')
	{
		Negative = true;
		b.erase(b.begin());
	}

	string Num1, Num2, Mul;
	if (a.length() == 0) a = "0";
	if (b.length() == 0) b = "0";
	int i, j, n = a.length(), m = b.length(), p = 0, q = 0;

	for (i = 0; i < n; i++)
	{
		if (a[i] != '.')
		{
			Num1 += a[i];
		}
		else
		{
			p = n - 1 - i;
		}
	}

	for (i = 0; i < m; i++)
	{
		if (b[i] != '.')
		{
			Num2 += b[i];
		}
		else
		{
			q = m - 1 - i;
		}
	}

	reverse(Num1.begin(), Num1.end());
	reverse(Num2.begin(), Num2.end());

	n = Num1.length();
	m = Num2.length();

	for (i = 0; i < n + m; i++)
	{
		Mul += '0';
	}

	//cout<<Num1<<" "<<Num2<<endl;

	for (i = 0; i < n; i++)
	{
		int Carry = 0;
		int temp1 = Num1[i] - '0';

		for (j = 0; j < m; j++)
		{
			// cout<<".";
			int temp2 = Num2[j] - '0';

			int temp = temp1 * temp2 + Mul[i + j] + Carry - 48;

			Mul[i + j] = (temp % 10) + 48;

			Carry = temp / 10;

			// cout<<Num1[i]<<" "<<Num2[j]<<" "<<temp<<" "<<Carry<<" "<<Mul[i+j]<<endl;
		}

		if (Carry) Mul[i + j] += Carry;
	}


	while (Mul.length() > 0 && Mul.back() == '0') Mul.pop_back();

	n = Mul.length();

	if (p + q > 0)
	{
		if (p + q > n)
		{
			for (i = n; i < p + q; i++)
			{
				Mul += '0';
			}
		}

		Mul.insert(Mul.begin() + p + q, '.');
		reverse(Mul.begin(), Mul.end());
		while (Mul.back() == '0') Mul.pop_back();
		if (Mul.back() == '.') Mul.pop_back();
	}

	else
	{
		reverse(Mul.begin(), Mul.end());
	}

	// cout<<Mul<<endl;
	if (Mul.length() > 0) return (Negative ? "-" : "") + Mul;
	return "0";
}
