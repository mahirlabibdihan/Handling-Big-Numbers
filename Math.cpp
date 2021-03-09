#include "Math.h"


string Scale(string a, int n=15, int round=0)
{
	int i, j, s = a.length();
	for (i = 0; i < s; i++)
	{
		if (a[i] == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
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


	a = Trim(a);
	return a;
}
string Ceil(string a)
{
	return Scale(a, 0, 1);
}
string Floor(string a)
{
	return Scale(a, 0, -1);
}
string Round(string a)
{
	return Scale(a, 0);
}

string Exponent(string a)
{
	a = Trim(a);

	string i, Result = "0", n = "40", P = "1", F = "1";
	for (i = "0"; Compare(i, n) < 1;)
	{
		if (Compare(i, "0") > 0)
		{
			P = Mul(P, a);
			F = Mul(F, i);
		}
		Result = Add(Result, Div(P, F));
		i = Add(i, "1");
	}
	return Result;
}

string Root(string n, string x)
{
	// cout<<n<<" "<<x<<endl;
	n = Trim(n);
	x = Trim(x);
	if (x.length() == 0) return n;
	string l = "0", r = n, m = "0";
	if (Compare(n, "1") < 1) r = "1";
	while (Compare(Sub(r, l), ".000000000001") == 1)
	{
		string temp = Div(Add(l, r), "2");
		if (Compare(m, temp) == 0)
		{
			break;
		}
		m = temp;
		(Compare(Pow(m, x), n) == 1) ? r = m : l = m;
		// cout<<l<<" "<<r<<" "<<m<<endl;
	}
	m = Trim(m);
	return m;
}
string Pow(string a, string b)
{
	// cout<<a<<" "<<b<<endl;
	a = Trim(a);
	b = Trim(b);
	if (Compare(b, "0") == 0) return "1";

	string c = "1";
	bool Negative = false;

	if (b[0] == '-')
	{
		Negative = true;
		b.erase(b.begin());
	}

	while (Compare(b, "0") == 1)
	{
		b = Sub(b, "1");
		c = Mul(c, a);
	}

	// cout<<c<<endl;
	if (Negative)
	{
		c = Div("1", c);
	}
	return c;
}

string GCD(string a,string b)
{
    while(Compare(a,"0")>0)
     {
        string c=a;
        a=Mod(b,a);
        b=c;
     }

     return b;
}

string LCM(string a,string b)
{
	 return Div(Mul(a,b),GCD(a,b));
}



string Mod(string Number, string Mod)
{
	if (Number.length() == 0) return Number;
	bool Negative = false;
	Number = Trim(Number);
	Mod = Trim(Mod);
	if (Compare(Mod, "0") < 1) return "∞";


	if (Number[0] == '-')
	{
		Number.erase(Number.begin());
		Negative = true;
	}
	string temp1 = DivDigit(Number, Mod);
	//cout<<temp1<<endl;
	string temp2 = Mul(Mod, temp1);
	string temp4 = Sub(Number, temp2);
	//cout<<Number<<" "<<Mod<<" "<<temp1<<" "<<temp2<<" "<<temp4<<endl;
	return (Negative ? "-" : "") + temp4;
}

string Power(string Number, string Power)
{
	// cout<<Number<<" "<<Power<<endl;
	Number = Trim(Number);
	Power = Trim(Power);
	pair<string,string> Num(Fraction(Power));
	// cout<<"->"<<Power<<" "<<Num<<" "<<Div<<endl;
	Number = Pow(Number, Num.first);
	// cout<<endl<<Num<<" "<<Div<<" "<<Number<<endl;
	if (Compare(Num.second, "1") > 0) return Root(Number,Num.second);
	return Number;
}

string Factorial(string n)
{
	n = Trim(n);
	string i, Fact = "1";
	for (i = "2"; Compare(i, n) < 1;)
	{
		Fact = Mul(Fact, i);
		i = Add(i, "1");
		// cout << "#######" << i << endl;
	}
	return Fact;
}

string NPR(string n,string r)
{
	string s="1",i=Add(Sub(n,r),"1");
	while(Compare(i,n)<1)
	{
		s=Mul(s,i);
		i=Add(i,"1");
	}
	return s;
}

string NCR(string n,string r)
{
	string s="1",i="1"; 
	if(Compare(r,Sub(n,r))>0) r=Sub(n,r);

	while(Compare(i,r)<1)
	{	
		s=Mul(s,Add(Sub(n,r),i));
		s=Div(s,i); 
		i=Add(i,"1");
	}

	return s;
}

string Abs(string a, string b)
{
	if (Compare(a, b) > -1) return Sub(a, b);
	return Sub(b, a);
}