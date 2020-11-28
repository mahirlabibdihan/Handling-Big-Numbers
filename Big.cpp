#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string Pi = "3.141592654";
int AddCarry;
int SubCarry;
string Num, Div;
string Sin(string);
string Cos(string);
string Tan(string);
string Csc(string);
string Sec(string);
string Cot(string);
string ASin(string);
string ACos(string);
string ATan(string);
string Csc(string);
string Sec(string);
string Cot(string);
string Sine(string);
string Trim(string);
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
string Add_Int(string, string);
string Divide(string, string);
string Multiply(string, string);
string Sub_Int(string, string);
string Sub_Frac(string, string);
string Substract(string, string);
string Add_Frac(string, string);
string ToDecimal(string, string);
string FromDecimal(string, string);
string Modulus(string, string);
string DivideDigit(string, string);
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
string Scale(string, int = 15, int = 0);
string DecimalTostring(unsigned long long);
string Bodmash(string);
bool hasPrecedence(char,char);
string applyOp(char,string, string);
unsigned long long stringToDecimal(string);
int Compare(string, string);
void Fraction(string);

string Bodmash(string expression)
{
	if (expression.length() == 0) return "0";

	stack<string> values;
	stack<char> ops;

	for (int i = 0; i <expression.length(); i++)
	 {
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

		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%' || expression[i] == '^') {

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

		else if(expression[i]== '!')
		{
			while (!ops.empty() && hasPrecedence(expression[i], ops.top()))
			{
				string value=values.top();
				values.pop();
				values.push(applyOp(ops.top(),value,value));
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
	string Decimal =values.top();
	values.pop();
	// System.out.println(FromDecimal(Decimal,To));
	return Decimal;
}
bool hasPrecedence(char op1, char op2) {
	if (op2 == '(' || op2 == ')')
		return false;
	if ((op1 == '^' || op1 == '*' || op1 == '/' || op1 == '%' ||op1=='!') && (op2 == '+' || op2 == '-'))
		return false;
	if ((op1 == '^'||op1=='!') && (op2 == '*' || op2 == '/' || op2 == '%'))
		return false;
	if(op1=='!'&&op2=='^')
		return false;
	else
		return true;
}

string applyOp(char op, string b, string a) {
	// cout<<op<<endl;
	switch (op) {
	case '+':
		return Add(a,b);
		break;
	case '-':
		return Substract(a,b);
		break;
	case '*':
		return Multiply(a,b);
		break;
	case '^':
		return Power(a, b);
		break;
	case '%':return Modulus(a,b);
		break;
	case '/':return Divide(a,b);
		break;
	case '!':return Factorial(b);
	}
	return "0";
}



	int main()
	{
		// string Num1, Num2, Deg;
		// cin >> Num1 >> Num2;
		// Num1= Trim(Num1);
		// Num2= Trim(Num2);
		// cout << Num1<<" + "<<Num2<<" = "<<Add(Num1, Num2)<<endl;
		// cout << Num1<<" - "<<Num2<<" = "<<Substract(Num1, Num2)<<endl;
		// cout << Num1<<" × "<<Num2<<" = "<<Multiply(Num1, Num2)<<endl;
		// cout << Num1<<" ÷ "<<Num2<<" = "<<Divide(Num1, Num2)<<endl;
		// // cout << Num1<<" ^ "<<Num2<<" = "<<Power(Num1, Num2)<<endl;
		// cout << Num1<<" % "<<Num2<<" = "<<Modulus(Num1, Num2)<<endl;
		// // cout << Num1<<"! = "<<fact(Num1)<<endl;
		// // cout << Num1<<" + "<<Num2<<" = "<<Compare(Num1,Num2)<<endl;

		// string Deg;
		// cin >> Deg;
		// cout << "sin(" << Deg << ") = " << Sin(Trim(Deg)) << endl;
		// cout << "cos(" << Deg << ") = " << Cos(Trim(Deg)) << endl;
		// cout << "tan(" << Deg << ") = " << Tan(Trim(Deg)) << endl;
		// cout << "csc(" << Deg << ") = " << Csc(Trim(Deg)) << endl;
		// cout << "sec(" << Deg << ") = " << Sec(Trim(Deg)) << endl;
		// cout << "cot(" << Deg << ") = " << Cot(Trim(Deg)) << endl;
		// cout<<Factorial(Deg);
		string V = "25";
		string m = "39.95";
		string T = "300";
		// cout<<Multiply ("4",Pi)<<endl;

		// for(;Compare(V,"1000")<0;)
		// {

			// cout<<V<<" -> "<<Scale(Multiply(Multiply(Pow(V,"2"),"12.566370616"),Multiply(Exponent(Multiply(Divide("-"+m,Multiply("2",Multiply(T,"8314"))),Pow(V,"2"))),Power(Divide(m,Multiply ("6.283185308",Multiply(T,"8314"))),"1.5"))),8)<<endl;
		// 	V=Add(V,"25");
		// }

		string In; 
		while(1)
		{
			getline(cin,In);
			cout<<Bodmash(In)<<endl;
		}
		
		// cout << Root(Divide( Multiply ( Multiply ( Multiply (Multiply ("6.67", Power("10", "-11")), Multiply("2", Multiply("1.99", Power("10", "30") ))))), Multiply("7", Power("10", "8"))), "2");
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
			Temp = Multiply(Digit, Two);
			Decimal = Add(Decimal, Temp);
			Two = Divide(Two, Base);
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
				string Mod = Modulus(DecimalInt, Base);

				if (Compare(Mod, "9") > 0)
				{
					char temp = Mod[1];
					Mod = "";
					Mod += temp + 'A' - '0';
				}
				NumberInt += Mod;
				DecimalInt = Floor(Divide(DecimalInt, Base));
			}
		}
		reverse(NumberInt.begin(), NumberInt.end());


		//cout<<DecimalFrac<<endl;
		if (DecimalFrac.length())
		{

			NumberFrac += '.';
			for (i = 0; i < 10 && DecimalFrac != "0"; i++)
			{
				string temp1 = Multiply(DecimalFrac, Base);
				string temp2 = Floor(temp1);
				//cout<<temp1<<" "<<temp2<<endl;
				DecimalFrac = Substract(temp1, temp2);
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
	string Scale(string a, int n, int round)
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
	string Exponent(string a)
	{
		a = Trim(a);

		string i, Result = "0", n = "40", P = "1", F = "1";
		for (i = "0"; Compare(i, n) < 1;)
		{
			if (Compare(i, "0") > 0)
			{
				P = Multiply(P, a);
				F = Multiply(F, i);
			}
			Result = Add(Result, Divide(P, F));
			i = Add(i, "1");
		}
		return Result;
	}
	string DivideDigit(string a, string b)
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
		return Substract(i, "1");
	}
	string Root(string n, string x)
	{
		// cout<<n<<" "<<x<<endl;
		n = Trim(n);
		x = Trim(x);
		if (x.length() == 0) return n;
		string l = "0", r = n, m = "0";
		if (Compare(n, "1") < 1) r = "1";
		while (Compare(Substract(r, l), ".000000000001") == 1)
		{
			string temp = Divide(Add(l, r), "2");
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
			b = Substract(b, "1");
			c = Multiply(c, a);
		}

		// cout<<c<<endl;
		if (Negative)
		{
			c = Divide("1", c);
		}
		return c;
	}
	void Fraction(string s)
	{

		Num = "";
		Div = "1";
		s = Trim(s);
		// cout<<s<<endl;
		string i, n = DecimalTostring(s.length());
		// cout<<" "<<s<<endl;
		for (i = "0"; Compare(n, i) == 1;)
		{
			if (s[stringToDecimal(i)] == '.')
			{
				for (string i = "1"; Compare(i, Substract(n, i)) < 0;)
				{
					Div += '0';
					i = Add(i, "1");
				}
				// cout<<"#####"<<Div<<endl;
			}
			else
			{
				Num += s[stringToDecimal(i)];
			}

			i = Add(i, "1");
		}

		// cout<<Num<<" "<<Div<<endl;
		while (Num[0] == '0') Num.erase(Num.begin());
		if (Num.length() == 0) Num = "0";
		string temp = Num;

		// cout<<endl<<Num<<" "<<Compare(Multiply("2","2"), temp)<<endl;
		for (i = "2"; Compare(i, Num) < 1;)
		{
			// cout<<i<<endl;
			if (Modulus(Num, i) == "0" && Modulus(Div, i) == "0")
			{
				Num = Divide(Num, i);
				Div = Divide(Div, i);
				// cout<<Modulus(Div, i)<<endl;
			}
			i = Add(i, "1");
			// cout<<" -"<<Div<<endl;
		}
	}
	string Modulus(string Number, string Mod)
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
		string temp1 = DivideDigit(Number, Mod);
		//cout<<temp1<<endl;
		string temp2 = Multiply(Mod, temp1);
		string temp4 = Substract(Number, temp2);
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
	string Divide(string a, string b)
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
				Div += DivideDigit(temp, Num2);
				temp = Modulus(temp, Num2);
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
			Div += DivideDigit(temp, Num2);
			//cout<<" -"<<Div<<endl;
			temp = Modulus(temp, Num2);

			if (++i < Num1.length())
				temp += Num1[i];
		}

		//cout<<Div<<" "<<temp<<endl;


		Div += (Compare(temp, "0") == 1) ? "." : "";

		for (; (i - Num1.length() < 11 && Compare(temp, "0") == 1); i++)
		{
			temp += '0';
			Div += DivideDigit(temp, Num2);
			temp = Modulus(temp, Num2);
		}

		if (i - Num1.length() == 11)
		{
			if (Div.back() == Div[Div.length() - 2] && Div.back() > '4')
				Div.back()++;
		}

		return (Negative ? "-" : "") + Div;
	}
	string FloatToInt(string Float)
	{
		string Int;
		int i, n = Float.length();
		for (i = 0; i < n; i++)
		{
			if (Float[i] == '.') break;
			Int += Float[i];
		}
		//cout<<Int<<endl;
		if (Int > "") return Int;
		return "0";
	}
	string Sub_Int(string a, string b)
	{
		string Substraction;
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

			Substraction += temp + 48;
		}

		reverse(Substraction.begin(), Substraction.end());
		return Substraction;
	}
	string Sub_Frac(string a, string b)
	{
		string Substraction;
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

			Substraction += temp + 48;
		}

		reverse(Substraction.begin(), Substraction.end());

		return (Substraction.length() > 0 ? "." : "") + Substraction;
	}
	string Substract(string Num1, string Num2)
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
		string Substraction = (Negative ? "-" : "") + SubInt + SubFrac;
		if (Substraction.length()) return Substraction;
		return "0";
	}
	string Multiply(string a, string b)
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
		else if (Num1[0] == '-') return Substract(Num2, Num1.substr(1, Num1.length() - 1));
		else if (Num2[0] == '-') return Substract(Num1, Num2.substr(1, Num2.length() - 1));
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
		Fraction(Power);
		// cout<<"->"<<Power<<" "<<Num<<" "<<Div<<endl;
		Number = Pow(Number, Num);
		// cout<<endl<<Num<<" "<<Div<<" "<<Number<<endl;
		if (Compare(Div, "1") > 0) return Root(Number, Div);
		return Number;
	}
	string Factorial(string n)
	{
		n = Trim(n);
		string i, Fact = "1";
		for (i = "2"; Compare(i, n) < 1;)
		{
			Fact = Multiply(Fact, i);
			i = Add(i, "1");
			// cout << "#######" << i << endl;
		}
		return Fact;
	}
	string Remainder(string Rad)
	{
		string i, j = "1";
		string P = "1", F = "1";
		for (i = "1"; Compare(j, "0.000000000005") > 0;)
		{
			P = Multiply(P, Rad);
			P = Multiply(P, Rad);
			F = Multiply(F, i);
			F = Multiply(F, Add(i, "1"));
			j = Divide(P, F);
			i = Add(i, "2");
			// cout<<i<<" "<<j<<endl;
		}

		return Substract(i, "2");
	}
	string Sine(string Deg)
	{
		//cout<<Deg<<endl;
		string Rad = Multiply(Divide(Deg, "180"), Pi);
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
				Term = Multiply(Term, Rad);
				// cout<<"2. "<<Term<<endl;
				Term = Multiply(Term, Rad);
				// cout<<"3. "<<Term<<endl;
				Term = Divide(Term, Substract(i, "1"));
				// cout<<"4. "<<Term<<endl;
				Term = Divide(Term, i);
				// cout<<"5. "<<Term<<endl;    //prob
			}
			// cout<<"\""<<Term<<endl;
			if (j % 2)
			{
				Result = Substract(Result, Term);
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
		if (Compare(a, b) > -1) return Substract(a, b);
		return Substract(b, a);
	}
	string Sin(string Deg)
	{

		Deg = Trim(Deg);
		Deg = Modulus(Deg, "360");
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
				return "-" + Sine(Substract("180", Deg));
			}
			else if (Compare(Deg, "180") > 0 && Compare(Deg, "270") < 1)
			{
				return Sine(Substract(Deg, "180"));
			}
			else
			{
				return Sine(Substract("360", Deg));
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
				return Sine(Substract("180", Deg));
			}
			else if (Compare(Deg, "180") > 0 && Compare(Deg, "270") < 1)
			{
				return "-" + Sine(Substract(Deg, "180"));
			}
			else
			{
				return "-" + Sine(Substract("360", Deg));
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
		string Result = Divide(Sin(Deg), Cos(Deg));
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
		string Result = Divide("1", Sin(Deg));
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
		string Result = Divide("1", Cos(Deg));
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
		string Result = Divide("1", Tan(Deg));

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
		Deg = Modulus(Deg, "360");

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


	/*
	+
	-
	*
	/
	%
	^
	!
	Fraction
	root
	abs
	sin
	cos
	tan
	csc
	sec
	cot
	*/
