/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

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

p	-> nPr

c 	-> nCr

l 	-> LCM

g 	-> GCD

&	-> And
	
|	-> Or

exit ->  Exit
###########################

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
string Bodmash(string);
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

double binaryExponentiation(double x,int n)
{
    if(n==0) return 1;
    else if(n%2 == 0) return binaryExponentiation(x*x,n/2);
    else return x*binaryExponentiation(x*x,(n-1)/2);
}

double Root(double n,double x)
{
	double l = 0, r = n, m = 0;
	if (n<=1) r = 1;
	while (r-l>.000000000001)
	{
		double temp = (l+r)/2;
		if (m==temp)
		{
			break;
		}
		m = temp;
		(binaryExponentiation(m,x)>n)? r = m : l = m;
	}
	return m;
}

pair<double,double> Fraction(double s)
{
	double WholeNum = s ,DecNum=1;

	int i,j;

	while(WholeNum-int(WholeNum)>.0000001)
	{	
		WholeNum*=10;
		DecNum*=10;

	}

	for (i =2; i<=WholeNum ;i++)
	{
		if (fmod(WholeNum , i)== 0 && fmod(DecNum , i)== 0)
		{
			WholeNum /= i;
			DecNum /=i ;
		}
	}
	return {WholeNum,DecNum}; 
}

double Power(double Number,double Power)
{
	pair<double,double> Num(Fraction(Power));
	Number =binaryExponentiation(Number, Num.first);
	if (Num.second> 1) return Root(Number,Num.second);
	return Number;
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

long double binaryExponentiation(long double x,int n)
{
    if(n==0) return 1;
    else if(n%2 == 0) return binaryExponentiation(x*x,n/2);
    else return x*binaryExponentiation(x*x,(n-1)/2);
}

double applyOp(char op, string b, string a) 
{
	// cout<<op<<endl;
	double A=stod(a),B=stod(b);
	switch (op) {
	case '+':
		return A+B;
		break;
	case '-':
		return A-B;
		break;
	case '*':
		return A*B;
		break;
	case '^':
		return Power(A,B);
		break;
	case '%': fmod(A,B);
		break;
	case '/': A/B;
		break;
	// case '!': return Factorial(b);
	// 	break;
	// case 'p': return NPR(a,b);
	// 	break;
	// case 'c': return NCR(a,b);
	// 	break;
	// case 'g': return GCD(a,b);
	// 	break;
	// case 'l': return LCM(a,b);
	// 	break;
	// case '&': return And(a,b);
	// 	break;
	// case '|': return Or(a,b);
	// 	break;
	}
	return 0;
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
				values.push(to_string(applyOp(ops.top(), value1, value2)));
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
				values.push(to_string(applyOp(ops.top(), value1, value2)));
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
				values.push(to_string(applyOp(ops.top(), value, value)));
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
		values.push(to_string(applyOp(ops.top(), value1, value2)));
		ops.pop();
	}
	string Decimal = values.top();
	values.pop();
	// System.out.println(FromDecimal(Decimal,To));
	return Decimal;
}



