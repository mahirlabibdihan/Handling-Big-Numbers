#include "Tri.h"
string Pi = "3.141592654";
string ATan(string n)
{
	 string l = "-90", r = "90", m = l;
	 n = Trim(n);

	while (Compare(Sub(r, l), ".000000001") == 1)
	{
		string temp = Div(Add(l, r), "2");
		if (Compare(m, temp) == 0)
		{
			break;
		}
		m = temp;
		(Compare(Tan(m), n) == 1) ? r = m : l = m;
		// cout<<l<<" "<<r<<" "<<m<<endl;
	}
	m = Trim(m);
	return m;
}
string ASin(string n)
{
	 string l = "-90", r = "90", m = l;
	 n = Trim(n);

	 while (Compare(Sub(r, l), ".000000001") == 1)
	{
		string temp = Div(Add(l, r), "2");
		if (Compare(m, temp) == 0)
		{
			break;
		}
		m = temp;
		(Compare(Sin(m), n) == 1) ? r = m : l = m;
		// cout<<l<<" "<<r<<" "<<m<<endl;
	}
	m = Trim(m);
	return m;
}
string ACos(string n)
{
	 string l = "-90", r = "90", m = l;
	 n = Trim(n);

	 while (Compare(Sub(r, l), ".000000001") == 1)
	{
		string temp = Div(Add(l, r), "2");
		if (Compare(m, temp) == 0)
		{
			break;
		}
		m = temp;
		(Compare(Cos(m), n) == 1) ? r = m : l = m;
		// cout<<l<<" "<<r<<" "<<m<<endl;
	}
	m = Trim(m);
	return m;
}
string ACot(string n)
{
	 string l = "-90", r = "90", m = l;
	 n = Trim(n);

	 while (Compare(Sub(r, l), ".000000001") == 1)
	{
		string temp = Div(Add(l, r), "2");
		if (Compare(m, temp) == 0)
		{
			break;
		}
		m = temp;
		(Compare(Cot(m), n) == 1) ? r = m : l = m;
		// cout<<l<<" "<<r<<" "<<m<<endl;
	}
	m = Trim(m);
	return m;
}
string ASec(string n)
{
	 string l = "-90", r = "90", m = l;
	 n = Trim(n);

	 while (Compare(Sub(r, l), ".000000001") == 1)
	{
		string temp = Div(Add(l, r), "2");
		if (Compare(m, temp) == 0)
		{
			break;
		}
		m = temp;
		(Compare(Sec(m), n) == 1) ? r = m : l = m;
		// cout<<l<<" "<<r<<" "<<m<<endl;
	}
	m = Trim(m);
	return m;
}
string ACsc(string n)
{
	 string l = "-90", r = "90", m = l;
	 n = Trim(n);

	 while (Compare(Sub(r, l), ".00000001") == 1)
	{
		string temp = Div(Add(l, r), "2");
		if (Compare(m, temp) == 0)
		{
			break;
		}
		m = temp;
		(Compare(Csc(m), n) == 1) ? r = m : l = m;
		// cout<<l<<" "<<r<<" "<<m<<endl;
	}
	m = Trim(m);
	return m;
}
string Sine(string Deg)
{
	//cout<<Deg<<endl;
	string Rad = Mul(Div(Deg, "180"), Pi);
	string i, Result = "0";

	string Term = Rad;

	// cout<<Term<<endl;
	int j;
	// string n=Remainder(Rad);
	string n = "17";
	// cout<<n<<" ";


	for (j = 0, i = "1"; Compare(i, n) < 1; j++)
	{
		if (Compare(i, "1") == 1)
		{
			// cout<<"1. "<<Term<<endl;
			Term = Mul(Term, Rad);
			// cout<<"2. "<<Term<<endl;
			Term = Mul(Term, Rad);
			// cout<<"3. "<<Term<<endl;
			Term = Div(Term, Sub(i, "1"));
			// cout<<"4. "<<Term<<endl;
			Term = Div(Term, i);
			// cout<<"5. "<<Term<<endl;    //prob
		}
		// cout<<"\""<<Term<<endl;
		if (j % 2)
		{
			Result = Sub(Result, Term);
		}
		else
		{
			// cout<<"####->"<<Result<<" "<<Term<<endl;
			Result = Add(Result, Term);
			// cout<<"####"<<Result<<endl;
		}
		i = Add(i, "2");
		//cout<<Result<<endl;
	}

	int k, s = Result.length();
	for (k = 0; k < s; k++)
	{
		if (Result[k] == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.pop_back();
	}

	Result = Trim(Result);

	return Result;
}
string Sin(string Deg)
{

	Deg = Trim(Deg);
	Deg = Mod(Deg, "360");
	// cout<<Deg<<endl;
	if (Deg[0] == '-')
	{
		Deg.erase(Deg.begin());
		if (Compare(Deg, "90") < 1)
		{
			return "-" + Sine(Deg);
		}
		else if (Compare(Deg, "90") > 0 && Compare(Deg, "180") < 1)
		{
			return "-" + Sine(Sub("180", Deg));
		}
		else if (Compare(Deg, "180") > 0 && Compare(Deg, "270") < 1)
		{
			return Sine(Sub(Deg, "180"));
		}
		else
		{
			return Sine(Sub("360", Deg));
		}
	}

	else
	{
		if (Compare(Deg, "90") < 1)
		{
			return Sine(Deg);
		}
		else if (Compare(Deg, "90") > 0 && Compare(Deg, "180") < 1)
		{
			return Sine(Sub("180", Deg));
		}
		else if (Compare(Deg, "180") > 0 && Compare(Deg, "270") < 1)
		{
			return "-" + Sine(Sub(Deg, "180"));
		}
		else
		{
			return "-" + Sine(Sub("360", Deg));
		}
	}
}
string Cos(string Deg)
{
	Deg = Trim(Deg);
	if (Deg[0] == '-') Deg.erase(Deg.begin());
	return Sin(Add("90", Deg));
}
string Tan(string Deg)
{
	string Result = Div(Sin(Deg), Cos(Deg));
	int k, j, s = Result.length();
	for (k = 0; k < s; k++)
	{
		if (Result[k] == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.pop_back();
	}

	return Trim(Result);
}
string Csc(string Deg)
{
	string Result = Div("1", Sin(Deg));
	int k, j, s = Result.length();
	for (k = 0; k < s; k++)
	{
		if (Result[k] == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.pop_back();
	}

	return Trim(Result);
}
string Sec(string Deg)
{
	string Result = Div("1", Cos(Deg));
	int k, j, s = Result.length();
	for (k = 0; k < s; k++)
	{
		if (Result[k] == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.pop_back();
	}

	return Trim(Result);
}
string Cot(string Deg)
{
	string Result = Div("1", Tan(Deg));

	int k, j, s = Result.length();
	for (k = 0; k < s; k++)
	{
		if (Result[k] == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.pop_back();
	}

	return Trim(Result);
}
string Trigonometry(string Deg, string Op)
{

	Deg = Trim(Deg);
	Deg = Mod(Deg, "360");

	if (Op == "sin")
	{
		return Sin(Deg);
	}

	else if (Op == "cos")
	{
		return Cos(Deg);
	}

	else if (Op == "tan")
	{
		return Tan(Deg);
	}

	else if (Op == "csc")
	{
		return Csc(Deg);
	}

	else if (Op == "sec")
	{
		return Sec(Deg);
	}
	else if (Op == "cot")
	{
		return Cot(Deg);
	}
	else return "0";
}
