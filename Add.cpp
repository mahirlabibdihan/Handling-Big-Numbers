#include "Add.h"
int AddCarry;
string Add_Int(string a, string b)
{
	string Addition;
	int i, n = a.length(), m = b.length();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (m > n) { swap(a, b); swap(n, m);}

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

		temp = temp1 + temp2 + AddCarry;
		AddCarry = temp / 10;
		Addition += (temp % 10) + 48;
	}

	if (AddCarry) Addition += AddCarry + '0';

	reverse(Addition.begin(), Addition.end());

	return Addition;
}

string Add_Frac(string a, string b)
{
	string Addition;
	int i, n = a.length(), m = b.length();

	if (m > n) { swap(a, b); swap(n, m); }

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

		temp = temp1 + temp2 + AddCarry;

		AddCarry = temp / 10;

		Addition += (temp % 10) + 48;
	}

	reverse(Addition.begin(), Addition.end());
	return (Addition.length() > 0 ? "." : "") + Addition;
}

string Add(string Num1, string Num2)
{
	Num1 = Trim(Num1);
	Num2 = Trim(Num2);
	bool Negative = false;
	if (Num1[0] == '-' && Num2[0] == '-')
	{
		Negative = true;
		Num1.erase(Num1.begin());
		Num2.erase(Num2.begin());
	}
	else if (Num1[0] == '-') return Sub(Num2, Num1.substr(1, Num1.length() - 1));
	else if (Num2[0] == '-') return Sub(Num1, Num2.substr(1, Num2.length() - 1));
	string Num1Int, Num1Frac, Num2Int, Num2Frac;

	int i, n = Num1.length(), m = Num2.length();

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

	string SumFrac = Add_Frac((Num1Frac > "" ? Num1Frac : "0"), (Num2Frac > "" ? Num2Frac : "0"));
	string SumInt = Add_Int((Num1Int > "" ? Num1Int : "0"), (Num2Int > "" ? Num2Int : "0"));

	while (SumInt[0] == '0') SumInt = SumInt.substr(1, SumInt.length());
	while (SumFrac.back() == '0') SumFrac.pop_back();
	if (SumFrac.back() == '.') SumFrac.pop_back();

	AddCarry = 0;
	return (Negative ? "-" : "") + (SumInt > "" ? SumInt : "0") + (SumFrac > "" ? SumFrac : "");
}