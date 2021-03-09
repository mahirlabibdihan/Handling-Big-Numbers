#include "Bit.h"
string And(string a,string b)
{
	string aBin=FromDecimal(a,"2"),bBin=FromDecimal(b,"2");

	string aBinInt="",aBinFrac="",bBinInt="",bBinFrac="",Int="",Frac="";

	int i,n=aBin.length(),m=bBin.length(),j;
	for (i = 0; i < n && aBin[i] != '.'; i++)
	{
		aBinInt += aBin[i];
	}

	for (i++; i < n; i++)
	{
		aBinFrac += aBin[i];
	}
	
	for (i = 0; i < m && aBin[i] != '.'; i++)
	{
		bBinInt += bBin[i];
	}

	for (i++; i < m ; i++)
	{
		bBinFrac += bBin[i];
	}

	n=aBinInt.length();
	m=bBinInt.length();

	for(i=n-1,j=m-1;i>-1||j>-1;i--,j--)
	{
		Int+=(((i>-1?aBinInt[i]:'0')-'0')&((j>-1?bBinInt[j]:'0')-'0'))+'0';
	}

	reverse(Int.begin(),Int.end());

	n=aBinFrac.length();
	m=bBinFrac.length();

	for(i=0,j=0;i<n||j<m;i++,j++)
	{
		Int+=(((i<n?aBinFrac[i]:'0')-'0')&((j<m?bBinFrac[j]:'0')-'0'))+'0';
	}

	return ToDecimal(Int+"."+Frac,"2");

}

string Or(string a,string b)
{ 

	string aBin=FromDecimal(a,"2"),bBin=FromDecimal(b,"2");

	string aBinInt="",aBinFrac="",bBinInt="",bBinFrac="",Int="",Frac="";

	int i,n=aBin.length(),m=bBin.length(),j;
	for (i = 0; i < n && aBin[i] != '.'; i++)
	{
		aBinInt += aBin[i];
	}

	for (i++; i < n; i++)
	{
		aBinFrac += aBin[i];
	}
	
	for (i = 0; i < m && aBin[i] != '.'; i++)
	{
		bBinInt += bBin[i];
	}

	for (i++; i < m ; i++)
	{
		bBinFrac += bBin[i];
	}


	n=aBinInt.length();
	m=bBinInt.length();


	for(i=n-1,j=m-1;i>-1||j>-1;i--,j--)
	{
		Int+=(((i>-1?aBinInt[i]:'0')-'0')|((j>-1?bBinInt[j]:'0')-'0'))+'0';
	}

	reverse(Int.begin(),Int.end());

	n=aBinFrac.length();
	m=bBinFrac.length();

	for(i=0,j=0;i<n||j<m;i++,j++)
	{
		Int+=(((i<n?aBinFrac[i]:'0')-'0')|((j<m?bBinFrac[j]:'0')-'0'))+'0';
	}

	return ToDecimal(Int+"."+Frac,"2");

}


string ToDecimal(string Number, string Base)
{
	// cout << Number << " " << Base << endl;
	Number = Trim(Number);
	bool Negative = (Number[0] == '-');
	string Decimal, P = "", Digit;
	Number = Number.substr(Negative, Number.length());
	int i, n = Number.length(), j = -1;

	while (++j < n)if (Number[j] == '.') break;

	// cout << j << endl;
	P += j + '0' - 1;
	// cout << P << endl;
	string Two = Pow(Base, P), Temp;
	// cout << Two << endl;

	for (i = 0; i < n; i++, Digit = "")
	{
		if (Number[i] == '.') continue;
		Digit += Number[i] > '9' ? "1" : "";
		Digit += ((Number[i] - '0') % 17) + '0';
		Temp = Mul(Digit, Two);
		Decimal = Add(Decimal, Temp);
		Two = Div(Two, Base);
	}
	return (Negative ? "-" : "") + Decimal;
}

string FromDecimal(string Decimal, string Base)
{
	string NumberInt, NumberFrac, DecimalInt, DecimalFrac;
	int i, n = Decimal.length();
	for (i = 0; i < n && Decimal[i] != '.'; i++)
	{
		DecimalInt += Decimal[i];
	}

	for (; i < n; i++)
	{
		DecimalFrac += Decimal[i];
	}

	if (DecimalInt.length())
	{
		while (DecimalInt > "0")
		{
			//cout<<"######1"<<endl;
			string mod = Mod(DecimalInt, Base);

			if (Compare(mod, "9") > 0)
			{
				char temp = mod[1];
				mod = "";
				mod += temp + 'A' - '0';
			}
			NumberInt += mod;
			DecimalInt = Floor(Div(DecimalInt, Base));
		}
	}
	reverse(NumberInt.begin(), NumberInt.end());


	//cout<<DecimalFrac<<endl;
	if (DecimalFrac.length())
	{

		NumberFrac += '.';
		for (i = 0; i < 10 && DecimalFrac != "0"; i++)
		{
			string temp1 = Mul(DecimalFrac, Base);
			string temp2 = Floor(temp1);
			//cout<<temp1<<" "<<temp2<<endl;
			DecimalFrac = Sub(temp1, temp2);
			if (Compare(temp2, "9") > 0)
			{
				char temp = temp2[1];
				temp2 = "";
				temp2 += temp + 'A' - '0';
			}
			NumberFrac += temp2;
		}
	}
	return NumberInt + NumberFrac;
}