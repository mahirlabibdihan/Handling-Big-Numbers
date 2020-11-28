/*

Author : Mahir Labib Dihan

*/


/*
###########################
(

)

+	-> Add

-	-> Substract

*	-> Multiply

/	-> Divide
	
%	-> Modulas

^	-> Power

!	-> Factorial

p   -> nPr

c   -> nCr

l   -> LCM

g   -> GCD

&	-> And
	
|	-> Or
###########################

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string Pi = "3.141592654";
int AddCarry;
int SubCarry;
string Sin(string);
string Cos(string);
string Tan(string);
string Csc(string);
string Sec(string);
string Cot(string);
string ASin(string);
string ACos(string);
string ATan(string);
string ACsc(string);
string ASec(string);
string ACot(string);
string Ceil(string);
string Round(string);
string Floor(string);
string Prime(string);
string Factorial(string);
string Add(string, string);
string Pow(string, string);
string NPR(string, string);
string NCR(string , string);
string GCD(string, string);
string LCM(string, string);
string Power(string, string);
string Remainder(string);
string Root(string, string);
string Exponent(string);
string Div(string, string);
string Mul(string, string);
string Sub(string, string);
string ToDecimal(string, string);
string FromDecimal(string, string);
string Mod(string, string);
string DivDigit(string, string);
string Abs(string, string);
string Trigonometry(string, string);
string And(string, string);
string Nand(string, string);
string Or(string, string);
string Nor(string, string);
string Not(string);
string Xor(string, string);
string XNor(string, string);
string Log(string, string);
string DecimalTostring(unsigned long long);
string Bodmash(string);
int Compare(string, string);
pair<string,string> Fraction(string);



int main()
{	
	string In;
	while (1)
	{
		cout<<": ";
		getline(cin, In);
		if(In=="exit") exit(0);
		cout << "-> "<<Bodmash(In) << endl<<endl;
	}
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

bool hasPrecedence(char op1, char op2) 
{
	if (op2 == '(' || op2 == ')')
		return false;
	if ((op1 == '^' || op1 == '*' || op1 == '/' || op1 == '%' || op1 == '!'||op1=='p'|| op1=='c'|| op1=='g'|| op1=='l'|| op1=='&'|| op1=='|') && (op2 == '+' || op2 == '-'))
		return false;
	if ((op1 == '^' || op1 == '!'|| op1=='p'|| op1=='c'|| op1=='g'|| op1=='l'|| op1=='&'|| op1=='|') && (op2 == '*' || op2 == '/' || op2 == '%'))
		return false;
	if((op1 == '!' || op1 == '^' )&&( op2=='p'|| op2=='c'|| op2=='g'|| op2=='l'|| op2=='&'|| op2=='|'))
		return false;
	if (op1 == '!' && op2 == '^')
		return false;
	else
		return true;
}

string applyOp(char op, string b, string a) 
{
	// cout<<op<<endl;
	switch (op) {
	case '+':
		return Add(a, b);
		break;
	case '-':
		return Sub(a, b);
		break;
	case '*':
		return Mul(a, b);
		break;
	case '^':
		return Power(a, b);
		break;
	case '%': return Mod(a, b);
		break;
	case '/': return Div(a, b);
		break;
	case '!': return Factorial(b);
		break;
	case 'p': return NPR(a,b);
		break;
	case 'c': return NCR(a,b);
		break;
	case 'g': return GCD(a,b);
		break;
	case 'l': return LCM(a,b);
		break;
	case '&': return And(a,b);
		break;
	case '|': return Or(a,b);
		break;
	}
	return "0";
}

string Bodmash(string expression)
{
	if (expression.length() == 0) return "";


	stack<string> values;
	stack<char> ops;

	for (int i = 0; i < expression.length(); i++)
	{
		if(expression[i]==' ') continue;
		if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
			string num = "";
			while (i < expression.length() && (expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.'))
				num += expression[i++];
			i--;
			values.push(num);
		}
		else if (expression[i] == '(') ops.push(expression[i]);

		else if (expression[i] == ')') {
			while (ops.top() != '(') {
				string value1, value2;
				if (!values.empty()) {
					value1 = values.top();
					values.pop();
				}
				else value1 = "0";
				if (!values.empty()) {
					value2 = values.top();
					values.pop();
				} else value2 = "0";
				values.push(applyOp(ops.top(), value1, value2));
				ops.pop();
			}
			ops.pop();
		}

		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%' || expression[i] == '^' ||expression[i] == 'p' ||expression[i] == 'c' ||expression[i] == 'g' ||expression[i] == 'l' ||expression[i] == '&' ||expression[i] == '|'  )
		 {
			while (!ops.empty() && hasPrecedence(expression[i], ops.top())) {
				string value1, value2;
				if (!values.empty()) {
					value1 = values.top();
					values.pop();
				}
				else value1 = "0";
				if (!values.empty()) {
					value2 = values.top();
					values.pop();
				} else value2 = "0";
				values.push(applyOp(ops.top(), value1, value2));
				ops.pop();
			}
			ops.push(expression[i]);
		}

		else if (expression[i] == '!')
		{
			while (!ops.empty() && hasPrecedence(expression[i], ops.top()))
			{
				string value = values.top();
				values.pop();
				values.push(applyOp(ops.top(), value, value));
				ops.pop();
			}
			ops.push(expression[i]);
		}
	}

	while (!ops.empty()) {
		string value1, value2;
		if (!values.empty()) {
			value1 = values.top();
			values.pop();
		}
		else value1 = "0";
		if (!values.empty()) {
			value2 = values.top();
			values.pop();
		} else
			value2 = "0";
		values.push(applyOp(ops.top(), value1, value2));
		ops.pop();
	}
	string Decimal = values.top();
	values.pop();
	// System.out.println(FromDecimal(Decimal,To));
	return Decimal;
}

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
	// int i, j, s = m.length();
	// for (i = 0; i < s; i++)
	// {
	// 	if (m[i] == '.') break;
	// }
	// //cout<<m.length()-i-4<<endl;
	// for (j = 0; j < s - i - 8; j++)
	// {
	// 	//	cout<<m<<endl;
	// 	m.pop_back();
	// }
	// cout<<"--->"<<m<<endl;

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

string Mul(string a, string b)
{
	// cout<<a<<" "<<b<<endl;
	a = Trim(a);
	b = Trim(b);
	if (Compare(a, "0") == 0 || Compare(b, "0") == 0) return "0";
	bool Negative = false;
	if (a[0] == '-' && b[0] == '-')
	{
		a.erase(a.begin());
		b.erase(b.begin());
	}

	else if (a[0] == '-')
	{
		Negative = true;
		a.erase(a.begin());
	}

	else if (b[0] == '-')
	{
		Negative = true;
		b.erase(b.begin());
	}

	string Num1, Num2, Mul;
	if (a.length() == 0) a = "0";
	if (b.length() == 0) b = "0";
	int i, j, n = a.length(), m = b.length(), p = 0, q = 0;

	for (i = 0; i < n; i++)
	{
		if (a[i] != '.')
		{
			Num1 += a[i];
		}
		else
		{
			p = n - 1 - i;
		}
	}

	for (i = 0; i < m; i++)
	{
		if (b[i] != '.')
		{
			Num2 += b[i];
		}
		else
		{
			q = m - 1 - i;
		}
	}

	reverse(Num1.begin(), Num1.end());
	reverse(Num2.begin(), Num2.end());

	n = Num1.length();
	m = Num2.length();

	for (i = 0; i < n + m; i++)
	{
		Mul += '0';
	}

	//cout<<Num1<<" "<<Num2<<endl;

	for (i = 0; i < n; i++)
	{
		int Carry = 0;
		int temp1 = Num1[i] - '0';

		for (j = 0; j < m; j++)
		{
			// cout<<".";
			int temp2 = Num2[j] - '0';

			int temp = temp1 * temp2 + Mul[i + j] + Carry - 48;

			Mul[i + j] = (temp % 10) + 48;

			Carry = temp / 10;

			// cout<<Num1[i]<<" "<<Num2[j]<<" "<<temp<<" "<<Carry<<" "<<Mul[i+j]<<endl;
		}

		if (Carry) Mul[i + j] += Carry;
	}


	while (Mul.length() > 0 && Mul.back() == '0') Mul.pop_back();

	n = Mul.length();

	if (p + q > 0)
	{
		if (p + q > n)
		{
			for (i = n; i < p + q; i++)
			{
				Mul += '0';
			}
		}

		Mul.insert(Mul.begin() + p + q, '.');
		reverse(Mul.begin(), Mul.end());
		while (Mul.back() == '0') Mul.pop_back();
		if (Mul.back() == '.') Mul.pop_back();
	}

	else
	{
		reverse(Mul.begin(), Mul.end());
	}

	// cout<<Mul<<endl;
	if (Mul.length() > 0) return (Negative ? "-" : "") + Mul;
	return "0";
}

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
string Abs(string a, string b)
{
	if (Compare(a, b) > -1) return Sub(a, b);
	return Sub(b, a);
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

	// cout<<aBinInt<<" "<<aBinFrac<<" "<<bBinInt<<" "<<bBinFrac<<endl; 

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


