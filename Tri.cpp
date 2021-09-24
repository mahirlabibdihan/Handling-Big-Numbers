#include "BigDecimal.h"
BigDecimal PI = "3.141592654";
BigDecimal aTan(BigDecimal n)
{
	 BigDecimal l = "-90", r = "90", m = l;
	 n.trim();

	while (r-l > ".000000001")
	{
		BigDecimal temp = (l + r) / "2";
		if (m == temp )
		{
			break;
		}
		m = temp;
		(tan(m) > n ) ? r = m : l = m;
	}
	return m.trim();
}
BigDecimal aSin(BigDecimal n)
{
	 BigDecimal l = "-90", r = "90", m = l;
	 n.trim();

	 while (r - l > ".000000001")
	{
		BigDecimal temp = (l + r) / "2";
		if (m == temp)
		{
			break;
		}
		m = temp;
		(sin(m) > n ) ? r = m : l = m;
	}
	return m.trim();
}
BigDecimal aCos(BigDecimal n)
{
	 BigDecimal l = "-90", r = "90", m = l;
	 n.trim();

	 while (r-l > ".000000001")
	{
		BigDecimal temp = (l + r) / "2";
		if (m == temp )
		{
			break;
		}
		m = temp;
		(cos(m) > n) ? r = m : l = m;
		// cout<<l<<" "<<r<<" "<<m<<endl;
	}
	return m.trim();
}
BigDecimal aCot(BigDecimal n)
{
	 BigDecimal l = "-90", r = "90", m = l;
	  n.trim();

	 while (r - l > ".000000001")
	{
		BigDecimal temp = (l + r) / "2";
		if (m == temp)
		{
			break;
		}
		m = temp;
		(cot(m) > n ) ? r = m : l = m;
	}
	return m.trim();
}
BigDecimal aSec(BigDecimal n)
{
	 BigDecimal l = "-90", r = "90", m = l;
	  n.trim();

	 while (r - l > ".000000001")
	{
		BigDecimal temp = (l + r) / "2";
		if (m == temp)
		{
			break;
		}
		m = temp;
		(sec(m) > n ) ? r = m : l = m;
	}
	return m.trim();
}
BigDecimal aCsc(BigDecimal n)
{
	 BigDecimal l = "-90", r = "90", m = l;
	 n.trim();

	 while (r - l > ".000000001")
	{
		BigDecimal temp = (l + r) / "2";
		if (m == temp)
		{
			break;
		}
		m = temp;
		(csc(m) > n ) ? r = m : l = m;
	}
	return m.trim();
}
BigDecimal sine(BigDecimal Deg)
{
	//cout<<Deg<<endl;
	BigDecimal Rad = (Deg * PI ) / "180";
	BigDecimal i, Result = "0";

	BigDecimal Term = Rad;

	// cout<<Term<<endl;
	int j;
	// BigDecimal n=Remainder(Rad);
	BigDecimal n = "17";
	// cout<<n<<" ";


	for (j = 0, i = "1"; i <= n ; j++)
	{
		if (i > "1")
		{
			// cout<<"1. "<<Term<<endl;
			Term = Term * Rad ;
			// cout<<"2. "<<Term<<endl;
			Term = Term * Rad ;
			// cout<<"3. "<<Term<<endl;
			Term = Term / (i - "1");
			// cout<<"4. "<<Term<<endl;
			Term = Term / i;
			// cout<<"5. "<<Term<<endl;    //prob
		}
		// cout<<"\""<<Term<<endl;
		cout<<"####->"<<Result<<" "<<Term<<endl;
		if (j % 2)
		{
			Result = Result - Term;
		}
		else
		{
			// cout<<"####->"<<Result<<" "<<Term<<endl;
			Result = Result + Term;
			// cout<<"####"<<Result<<endl;
		}
		i = i + "2";
		cout<<Result<<endl;
	}

	int k, s = Result.getString().length();
	for (k = 0; k < s; k++)
	{
		if (Result.getString().charAt(k) == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.getString().pop_back();
	}

	return Result.trim();
}
BigDecimal sin(BigDecimal Deg)
{

	Deg.trim();
	Deg = Deg % "360";
	// cout<<Deg<<endl;
	if (Deg.getString().front() == '-')
	{
		Deg.getString().pop_front();
		if (Deg <= "90")
		{
			return "-" + sine(Deg).toString();
		}
		else if ( Deg > "90" && Deg <= "180")
		{
			return "-" + sine("180" - Deg).toString();
		}
		else if (Deg > "180" && Deg <= "270")
		{
			return sine(Deg - "180");
		}
		else
		{
			return sine("360" - Deg);
		}
	}

	else
	{
		if (Deg <= "90")
		{
			return sine(Deg);
		}
		else if (Deg > "90" && Deg <= "180")
		{
			return sine("180" - Deg);
		}
		else if (Deg > "180" && Deg <= "270")
		{
			return "-" + sine(Deg - "180").toString();
		}
		else
		{
			return "-" + sine("360" - Deg).toString();
		}
	}
}
BigDecimal cos(BigDecimal Deg)
{
	Deg.trim();
	if (Deg.getString().front() == '-') Deg.getString().pop_front();
	return sin(Deg + "90");
}
BigDecimal tan(BigDecimal Deg)
{
	BigDecimal Result = sin(Deg) / cos(Deg);
	int k, j, s = Result.getString().length();
	for (k = 0; k < s; k++)
	{
		if (Result.getString().charAt(k) == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.getString().pop_back();
	}

	return Result.trim();
}
BigDecimal csc(BigDecimal Deg)
{
	BigDecimal Result = "1" / sin(Deg);
	int k, j, s = Result.getString().length();
	for (k = 0; k < s; k++)
	{
		if (Result.getString().charAt(k) == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.getString().pop_back();
	}

	return Result.trim();
}
BigDecimal sec(BigDecimal Deg)
{
	BigDecimal Result = "1" / cos(Deg);
	int k, j, s = Result.getString().length();
	for (k = 0; k < s; k++)
	{
		if (Result.getString().charAt(k) == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.getString().pop_back();
	}

	return Result.trim();
}
BigDecimal cot(BigDecimal Deg)
{
	BigDecimal Result = "1" / tan(Deg);
	int k, j, s = Result.getString().length();
	for (k = 0; k < s; k++)
	{
		if (Result.getString().charAt(k) == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - k - 11; j++)
	{
		//	cout<<m<<endl;
		Result.getString().pop_back();
	}

	return Result.trim();
}
/*BigDecimal Trigonometry(BigDecimal Deg, BigDecimal Op)
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
}*/
