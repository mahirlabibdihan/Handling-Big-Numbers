#include "Div.h"
pair<string,string> Fraction(string s)
{
	string WholeNum = "",DecNum = "1";
	s = Trim(s);
	// cout<<s<<endl;
	string i, n = DecimalTostring(s.length());
	// cout<<" "<<s<<endl;
	for (i = "0"; Compare(n, i) == 1;)
	{
		if (s[stringToDecimal(i)] == '.')
		{
			for (string i = "1"; Compare(i, Sub(n, i)) < 0;)
			{
				DecNum += '0';
				i = Add(i, "1");
			}
			// cout<<"#####"<<Div<<endl;
		}
		else
		{
			WholeNum += s[stringToDecimal(i)];
		}

		i = Add(i, "1");
	}

	// cout<<Num<<" "<<Div<<endl;
	while (WholeNum[0] == '0') WholeNum.erase(WholeNum.begin());
	if (WholeNum.length() == 0) WholeNum = "0";
	string temp = WholeNum;

	// cout<<endl<<Num<<" "<<Compare(Mul("2","2"), temp)<<endl;
	for (i = "2"; Compare(i, WholeNum) < 1;)
	{
		// cout<<i<<endl;
		if (Mod(WholeNum, i) == "0" && Mod(DecNum, i) == "0")
		{
			WholeNum = Div(WholeNum, i);
			DecNum = Div(DecNum, i);
			// cout<<Mod(Div, i)<<endl;
		}
		i = Add(i, "1");
		// cout<<" -"<<Div<<endl;
	}
	return pair<string,string>(WholeNum,DecNum); 
}
string DivDigit(string a, string b)
{
	a = Trim(a);
	b = Trim(b);
	if (Compare(b, "0") == 0) return "∞";
	string i, j = "0";
	for (i = "0"; Compare(j, a) < 1;)
	{
		j = Add(j, b);
		i = Add(i, "1");
	}
	return Sub(i, "1");
}
string Remainder(string Rad)
{
	string i, j = "1";
	string P = "1", F = "1";
	for (i = "1"; Compare(j, "0.000000000005") > 0;)
	{
		P = Mul(P, Rad);
		P = Mul(P, Rad);
		F = Mul(F, i);
		F = Mul(F, Add(i, "1"));
		j = Div(P, F);
		i = Add(i, "2");
		// cout<<i<<" "<<j<<endl;
	}

	return Sub(i, "2");
}
string Div(string a, string b)
{
	// cout<<a<<" "<<b<<endl;
	a = Trim(a);
	b = Trim(b);

	if (Compare(b, "0") == 0) return "∞";
	//cout<<a<<" "<<b<<endl;
	bool Negative = false;


	if (a[0] == '-' && b[0] == '-')
	{
		a.erase(a.begin());
		b.erase(b.begin());
	}
	else if (a[0] == '-')
	{
		a = a.substr(1, a.length());
		Negative = true;
	}
	else if (b[0] == '-')
	{
		b = b.substr(1, b.length());
		Negative = true;
	}

	string Div;
	string Num1, Num2;

	int i, p = 0, q = 0;

	for (i = 0; i < a.length(); i++)
	{
		if (a[i] == '.')
		{
			p = a.length() - 1 - i;
		}
		else
		{
			Num1 += a[i];
		}
	}

	for (i = 0; i < b.length(); i++)
	{
		if (b[i] == '.')
		{
			q = b.length() - 1 - i;
		}
		else
		{
			Num2 += b[i];
		}
	}

	// cout<<Num1<<" "<<Num2<<endl;

	if (p > q)
	{
		for (i = 0; i < p - q; i++)
		{
			Num2 += '0';
		}
	}

	else if (p < q)
	{
		for (i = 0; i < q - p; i++)
		{
			Num1 += '0';
		}
	}

	// cout<<Num1<<" "<<Num2<<" "<<endl;

	string temp;

	if (Compare(Num2, Num1) == 1)
	{
		// cout<<"######"<<endl;
		temp = Num1 + "0";
		Div = ".";


		// cout<<Div<<" "<<temp<<endl;

		for (i = 0; i < 15 && Compare(temp, "0") == 1; i++)
		{
			Div += DivDigit(temp, Num2);
			temp = Mod(temp, Num2);
			temp += '0';
			// cout<<"-"<<Div<<endl;
		}

		return (Negative ? "-" : "") + Div;
	}


	for (i = -1; Compare(Num2, temp) == 1;)
	{
		temp += Num1[++i];
	}



	for (; (i < Num1.length());)
	{
		Div += DivDigit(temp, Num2);
		//cout<<" -"<<Div<<endl;
		temp = Mod(temp, Num2);

		if (++i < Num1.length())
			temp += Num1[i];
	}

	//cout<<Div<<" "<<temp<<endl;


	Div += (Compare(temp, "0") == 1) ? "." : "";

	for (; (i - Num1.length() < 11 && Compare(temp, "0") == 1); i++)
	{
		temp += '0';
		Div += DivDigit(temp, Num2);
		temp = Mod(temp, Num2);
	}

	if (i - Num1.length() == 11)
	{
		if (Div.back() == Div[Div.length() - 2] && Div.back() > '4')
			Div.back()++;
	}

	return (Negative ? "-" : "") + Div;
}
