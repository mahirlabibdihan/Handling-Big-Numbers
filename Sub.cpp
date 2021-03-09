#include "Sub.h"
int SubCarry;
string Sub_Int(string a, string b)
{
	string Subion;
	int i, n = a.length(), m = b.length();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());


	int p = max(m, n);

	for (i = 0; i < p; i++)
	{
		int temp, temp1, temp2;

		if (i > n - 1)
		{
			temp1 = 0;
		}
		else
		{
			temp1 = a[i] - 48;
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b[i] - 48;
		}

		temp = temp1 - temp2 + 10 * (SubCarry + temp2 > temp1) - SubCarry;
		SubCarry = (SubCarry + temp2 > temp1);

		Subion += temp + 48;
	}

	reverse(Subion.begin(), Subion.end());
	return Subion;
}

string Sub_Frac(string a, string b)
{
	string Subion;
	int i, n = a.length(), m = b.length();

	int p = max(m, n);

	for (i = p - 1; i > -1; i--)
	{
		int temp, temp1, temp2;
		if (i > n - 1)
		{
			temp1 = 0;
		}
		else
		{
			temp1 = a[i] - 48;
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b[i] - 48;
		}

		temp = temp1 - temp2 + 10 * (SubCarry + temp2 > temp1) - SubCarry;
		SubCarry = (SubCarry + temp2 > temp1);

		Subion += temp + 48;
	}

	reverse(Subion.begin(), Subion.end());

	return (Subion.length() > 0 ? "." : "") + Subion;
}

string Sub(string Num1, string Num2)
{
	Num1 = Trim(Num1);
	Num2 = Trim(Num2);
	if (Num1[0] == '-' && Num2[0] == '-')
	{
		swap(Num1, Num2);

	}
	else if (Num1[0] == '-')
	{
		return Add(Num1, "-" + Num2);
	}
	else if (Num2[0] == '-') return Add(Num1, Num2.substr(1, Num2.length() - 1));
	string Num1Int, Num1Frac, Num2Int, Num2Frac;
	int i, n = Num1.length(), m = Num2.length();
	bool Negative = false;

	for (i = 0; i < n & Num1[i] != '.'; i++)
	{
		Num1Int += Num1[i];
	}

	for (i++; i < n; i++)
	{
		Num1Frac += Num1[i];
	}

	for (i = 0; i < m & Num2[i] != '.'; i++)
	{
		Num2Int += Num2[i];
	}

	for (i++; i < m; i++)
	{
		Num2Frac += Num2[i];
	}

	if (Num1Int.length() == 0) Num1Int = "0";
	if (Num2Int.length() == 0) Num2Int = "0";

	string SubFrac, SubInt;

	if (Compare(Num1, Num2) < 0)
	{
		SubFrac = Sub_Frac(Num2Frac, Num1Frac);
		SubInt = Sub_Int(Num2Int, Num1Int);
		Negative = true;
	}
	else
	{
		SubFrac = Sub_Frac(Num1Frac, Num2Frac);
		SubInt = Sub_Int(Num1Int, Num2Int);
	}

	if (SubInt.length())
		while (SubInt[0] == '0')
		{
			SubInt = SubInt.substr(1, SubInt.length());
		}

	if (SubFrac.length())
	{
		while (SubFrac.back() == '0')
		{
			SubFrac.pop_back();
		}
		if (SubFrac.back() == '.')
		{
			SubFrac.pop_back();
		}
	}
	SubCarry = 0;
	string Subion = (Negative ? "-" : "") + SubInt + SubFrac;
	if (Subion.length()) return Subion;
	return "0";
}