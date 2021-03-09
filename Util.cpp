#include "Util.h"
int Compare(string a, string b)
{
	a = Trim(a);
	b = Trim(b);
	//cout<<"->"<<a<<" "<<b<<endl;
	int i, n = a.length(), m = b.length();
	string Num1Int, Num1Frac, Num2Int, Num2Frac;

	for (i = 0; i < n; i++)
	{
		if (a[i] == '.') break;
		Num1Int += a[i];
	}
	for (i++; i < n; i++)
	{
		Num1Frac += a[i];
	}

	for (i = 0; i < m; i++)
	{
		if (b[i] == '.') break;
		Num2Int += b[i];
	}
	for (i++; i < m; i++)
	{
		Num2Frac += b[i];
	}

	if (Num1Int[0] == '-')
		while (Num1Int.length() > 0 && Num1Int[0] == '0')
		{
			Num1Int.erase(Num1Int.begin() + 1);
		}

	else
		while (Num1Int.length() > 0 && Num1Int[0] == '0')
		{
			Num1Int.erase(Num1Int.begin());
		}

	if (Num2Int[0] == '-')
		while (Num2Int.length() > 0 && Num2Int[0] == '0')
		{
			Num2Int.erase(Num2Int.begin() + 1);
		}

	else
		while (Num2Int.length() > 0 && Num2Int[0] == '0')
		{
			Num2Int.erase(Num2Int.begin());
		}

	while (Num1Frac.length() > 0 && Num1Frac.back() == '0')
	{
		Num1Frac.pop_back();
	}
	while (Num2Frac.length() > 0 && Num2Frac.back() == '0')
	{
		Num2Frac.pop_back();
	}

	if (Num1Int.length() == 0) Num1Int = "0";
	if (Num2Int.length() == 0) Num2Int = "0";
	if (Num1Frac.length() == 0) Num1Frac = "0";
	if (Num2Frac.length() == 0) Num2Frac = "0";
	// cout<<endl<<"->1."<<Num1Int<<" 2."<<Num1Frac<<" 3."<<Num2Int<<" 4."<<Num2Frac<<endl;

	if (Num1Int[0] == '-' && Num2Int[0] != '-') return -1;
	else if (Num1Int[0] != '-' && Num2Int[0] == '-') return 1;

	if (Num1Int.length() > Num2Int.length()) return 1;
	else if (Num1Int.length() == Num2Int.length())
	{
		if (Num1Int > Num2Int) return 1;
		else if (Num1Int == Num2Int)
		{
			if (Num1Frac > Num2Frac) return 1;
			else if (Num1Frac < Num2Frac) return -1;
			else return 0;
		}
		else return -1;
	}
	else return -1;
}


string Trim(string a)
{
	if (a == "∞") return a;
	string Int, Frac;
	int i, n = a.length();

	for (i = 0; i < n; i++)
	{
		if (a[i] == '.') break;
		Int += a[i];
	}
	for (; i < n; i++)
	{
		Frac += a[i];
	}

	if (Int[0] == '-')
		while (Int.length() > 0 && Int[0] == '0')
		{
			Int.erase(Int.begin() + 1);
		}

	else
		while (Int.length() > 0 && Int[0] == '0')
		{
			Int.erase(Int.begin());
		}

	while (Frac.length() > 0 && Frac.back() == '0')
	{
		Frac.pop_back();
	}
	if (Frac.length() > 0 && Frac.back() == '.')
	{
		Frac.pop_back();
	}

	string Number = Int + Frac;
	if (Number.length() > 0) return Number;
	return "0";
}

unsigned long long stringToDecimal(string Number)
{
	Number = Trim(Number);
	unsigned long long Decimal = 0;
	int n = Number.length(), i;

	for (i = 0; i < n; i++)
	{
		Decimal *= 10;
		Decimal += Number[i] - 48;
	}

	return Decimal;
}


string DecimalTostring(unsigned long long Decimal)
{
	string Number;
	while (Decimal > 0)
	{
		Number += 48 + Decimal % 10;
		Decimal /= 10;
	}
	reverse(Number.begin(), Number.end());

	return Trim(Number);
}
