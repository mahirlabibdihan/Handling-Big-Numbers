#include "BigDecimal.h"
int BigDecimal::compareTo(BigDecimal b)
{	
	BigDecimal a(*this);
	a.trim();
	b.trim();
	// cout<<a<<" "<<b<<endl;
	int i, n = a.getString().length(), m = b.getString().length();
	BigDecimal Num1Int, Num1Frac, Num2Int, Num2Frac;

	for (i = 0; i < n; i++)
	{
		if (a.isDecimalPoint(i)) break;
		Num1Int.getString().push_back(a.getString().charAt(i));
	}
	for (i++; i < n; i++)
	{
		Num1Frac.getString().push_back(a.getString().charAt(i));
	}
	for (i = 0; i < m; i++)
	{
		if (b.isDecimalPoint(i)) break;
		Num2Int.getString().push_back(b.getString().charAt(i));
	}
	for (i++; i < m; i++)
	{
		Num2Frac.getString().push_back(b.getString().charAt(i));
	}


	if (Num1Int.getString().empty()) Num1Int = "0";
	if (Num2Int.getString().empty()) Num2Int = "0";
	if (Num1Frac.getString().empty()) Num1Frac = "0";
	if (Num2Frac.getString().empty()) Num2Frac = "0";
	// cout<<endl<<"->1."<<Num1Int<<" 2."<<Num1Frac<<" 3."<<Num2Int<<" 4."<<Num2Frac<<endl;

	// cout<<Num1Int<<"C"<<int(Num2Int.getString().charAt(0))<<endl;
	if (Num1Int.isNegative() && !Num2Int.isNegative()) {
		return -1;
	}
	else if (!Num1Int.isNegative() && Num2Int.isNegative()) {
		return 1;
	}


	if (Num1Int.getString().length() > Num2Int.getString().length()) {
		return 1;
	}
	else if (Num1Int.getString().length() == Num2Int.getString().length())
	{
		// cout<<"PASS"<<endl;
		if (Num1Int.getString().compare(Num2Int.getString()) > 0) {
			// cout<<"BUG"<<endl;
			return 1;
		}
		else if (Num1Int.getString().compare(Num2Int.getString()) == 0)
		{
			if (Num1Frac.getString().compare(Num2Frac.getString())>0) return 1;
			else if (Num1Frac.getString().compare(Num2Frac.getString())<0) return -1;
			else return 0;
		}
		else 
		{
			return -1;
		}
	}
	else return -1;
}

BigDecimal BigDecimal::trim()
{

	if (this->getString() == "∞") {
		return *this;
	}


	BigDecimal Int, Frac;

	int i, n = this->getString().length();

	
	for (i = 0; i < n; i++)
	{
		if (this->isDecimalPoint(i)) break;
		Int.getString().push_back(s[i]);
	}
	for (; i < n; i++)
	{
		Frac.getString().push_back(s[i]);
	}


	if (Int.isNegative())
	{
		while (Int.getString().length() > 1 && Int.digitAt(1) == 0)
		{
			Int.getString().erase(1);
		}
	}

	else
	{
		while (!Int.getString().empty() && Int.front() == 0)
		{
			Int.getString().pop_front();
		}
	}


	while (!Frac.getString().empty() && Frac.back() == 0)
	{
		Frac.getString().pop_back();
	}

	if (!Frac.getString().empty() && Frac.getString().back() == '.')
	{
		Frac.getString().pop_back();
	}

	getString().set(Int.getString()+Frac.getString());

	if (this->getString().empty())
	{
		*this = "0";
	}

	return *this;
}

unsigned long long BigDecimal::BigDecimalToDecimal(BigDecimal Number)
{
	Number.trim();
	unsigned long long Decimal = 0;
	int n = Number.getString().length(), i;

	for (i = 0; i < n; i++)
	{
		Decimal *= 10;
		Decimal += Number.digitAt(i);
	}

	return Decimal;
}


BigDecimal BigDecimal::DecimalToBigDecimal(unsigned long long Decimal)
{
	BigDecimal Number;
	while (Decimal > 0)
	{
		Number.getString().push_back('0' + Decimal % 10);
		Decimal /= 10;
	}
	Number.reverse();

	return Number.trim();
}
