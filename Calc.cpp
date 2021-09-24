#include "BigDecimal.h"
/*bool BigDecimal::hasPrecedence(char op1, char op2)
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

String BigDecimal::applyOp(char op, String b, String a)
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

String BigDecimal::Calculate(String expression)
{
	if (expression.length() == 0) return "";


	stack<String> values;
	stack<char> ops;

	for (int i = 0; i < expression.length(); i++)
	{
		if(expression[i]==' ') continue;
		if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
			String num = "";
			while (i < expression.length() && (expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.'))
				num += expression[i++];
			i--;
			values.push(num);
		}
		else if (expression[i] == '(') ops.push(expression[i]);

		else if (expression[i] == ')') {
			while (ops.top() != '(') {
				String value1, value2;
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
				String value1, value2;
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
				String value = values.top();
				values.pop();
				values.push(applyOp(ops.top(), value, value));
				ops.pop();
			}
			ops.push(expression[i]);
		}
	}

	while (!ops.empty()) {
		String value1, value2;
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
	String Decimal = values.top();
	values.pop();
	// System.out.println(FromDecimal(Decimal,To));
	return Decimal;
}*/