#include "BigDecimal.h"


BigDecimal BigDecimal::operator&(BigDecimal b)
{
	BigDecimal aBin = fromDecimal(*this, "2"), bBin = fromDecimal(b, "2");

	BigDecimal aBinInt = "", aBinFrac = "", bBinInt = "", bBinFrac = "", Int = "", Frac = "";

	int i, n = aBin.getString().length(), m = bBin.getString().length(), j;
	for (i = 0; i < n && aBin.getString().charAt(i) != '.'; i++)
	{
		aBinInt.getString().push_back(aBin.getString().charAt(i));
	}

	for (i++; i < n; i++)
	{
		aBinFrac.getString().push_back(aBin.getString().charAt(i));
	}

	for (i = 0; i < m && bBin.getString().charAt(i) != '.'; i++)
	{
		bBinInt.getString().push_back(bBin.getString().charAt(i));
	}

	for (i++; i < m; i++)
	{
		bBinFrac.getString().push_back(bBin.getString().charAt(i));
	}

	n = aBinInt.getString().length();
	m = bBinInt.getString().length();

	for (i = n - 1, j = m - 1; i > -1 || j > -1; i--, j--)
	{
		Int.getString().push_back((((i > -1 ? aBinInt.digitAt(i) : 0)) & ((j > -1 ? bBinInt.digitAt(j) : 0))) + '0');
	}

	Int.reverse();

	n = aBinFrac.getString().length();
	m = bBinFrac.getString().length();

	for (i = 0, j = 0; i < n || j < m; i++, j++)
	{
		Int.getString().push_back((((i < n ? aBinFrac.digitAt(i) : 0)) & ((j < m ? bBinFrac.digitAt(j) : 0))) + '0');
	}

	return toDecimal(BigDecimal(Int.toString() + "." + Frac.toString()), BigDecimal("2"));
}

BigDecimal BigDecimal::operator|(BigDecimal b)
{
	BigDecimal aBin = fromDecimal(*this, "2"), bBin = fromDecimal(b, "2");

	BigDecimal aBinInt = "", aBinFrac = "", bBinInt = "", bBinFrac = "", Int = "", Frac = "";

	int i, n = aBin.getString().length(), m = bBin.getString().length(), j;
	for (i = 0; i < n && aBin.getString().charAt(i) != '.'; i++)
	{
		aBinInt.getString().push_back(aBin.getString().charAt(i));
	}

	for (i++; i < n; i++)
	{
		aBinFrac.getString().push_back(aBin.getString().charAt(i));
	}

	for (i = 0; i < m && bBin.getString().charAt(i) != '.'; i++)
	{
		bBinInt.getString().push_back(bBin.getString().charAt(i));
	}

	for (i++; i < m; i++)
	{
		bBinFrac.getString().push_back(bBin.getString().charAt(i));
	}

	n = aBinInt.getString().length();
	m = bBinInt.getString().length();

	for (i = n - 1, j = m - 1; i > -1 || j > -1; i--, j--)
	{
		Int.getString().push_back((((i > -1 ? aBinInt.digitAt(i) : 0)) | ((j > -1 ? bBinInt.digitAt(j) : 0))) + '0');
	}

	Int.reverse();

	n = aBinFrac.getString().length();
	m = bBinFrac.getString().length();

	for (i = 0, j = 0; i < n || j < m; i++, j++)
	{
		Int.getString().push_back((((i < n ? aBinFrac.digitAt(i) : 0)) | ((j < m ? bBinFrac.digitAt(j) : 0))) + '0');
	}

	return toDecimal(BigDecimal(Int.toString() + "." + Frac.toString()), BigDecimal("2"));
}

BigDecimal toDecimal(BigDecimal Number, BigDecimal Base)
{
	// cout << Number << " " << Base << endl;
	Number.trim();
	bool negative = false;
	if (Number.toString().front() == '-') {
		negative = true;
		Number.getString().pop_front();
	}

	BigDecimal Decimal, P = "", Digit;
	int i, n = Number.toString().length(), j = -1;

	while (++j < n)if (Number.toString().charAt(j) == '.') break;

	// cout << j << endl;
	P.getString().push_back(j + '0' - 1);
	// cout << P << endl;
	BigDecimal Two = Base ^ P, Temp;
	// cout << Two << endl;

	for (i = 0; i < n; i++, Digit = "")
	{
		if (Number.toString().charAt(i) == '.') continue;
		Digit.getString().push_back(Number.toString().charAt(i) > '9' ? "1" : "");
		Digit.getString().push_back(((Number.toString().charAt(i) - '0') % 17) + '0');
		Temp = Digit * Two;
		Decimal = Decimal + Temp;
		Two = Two / Base;
	}
	return (negative ? "-" : "") + Decimal.toString();
}

BigDecimal fromDecimal(BigDecimal Decimal, BigDecimal Base)
{
	BigDecimal NumberInt, NumberFrac, DecimalInt, DecimalFrac;
	int i, n = Decimal.toString().length();
	bool negative = false;
	if (Decimal.toString().front() == '-') {
		negative = true;
		Decimal.getString().pop_front();
	}
	for (i = 0; i < n && Decimal.toString().charAt(i) != '.'; i++)
	{
		DecimalInt.getString().push_back(Decimal.toString().charAt(i));
	}

	for (; i < n; i++)
	{
		DecimalFrac.getString().push_back(Decimal.toString().charAt(i));
	}

	if (DecimalInt.toString().length())
	{
		while (DecimalInt > "0")
		{
			//cout<<"######1"<<endl;
			BigDecimal mod = DecimalInt % Base;

			if (mod > "9")
			{
				char temp = mod.toString().charAt(1);
				mod = "";
				mod.getString().push_back(temp + 'A' - '0');
			}
			NumberInt.getString().push_back(mod.toString());
			DecimalInt = floor(DecimalInt / Base);
			// cout<<NumberInt<<endl;
		}
	}
	NumberInt.reverse();

	if (DecimalFrac.toString().length())
	{
		NumberFrac.getString().push_back('.');
		for (i = 0; i < 10 && DecimalFrac != "0"; i++)
		{
			BigDecimal temp1 = DecimalFrac * Base;
			BigDecimal temp2 = floor(temp1);
			//cout<<temp1<<" "<<temp2<<endl;
			DecimalFrac = temp1 - temp2;
			if (temp2 > "9")
			{
				char temp = temp2.toString().charAt(1);
				temp2 = "";
				temp2.toString().push_back(temp + 'A' - '0');
			}
			NumberFrac.getString().push_back(temp2.toString());
		}
	}
	return (negative ? "-" : "") + NumberInt.toString() + NumberFrac.toString();
}