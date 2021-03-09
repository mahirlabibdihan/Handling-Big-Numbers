#ifndef __BIG_DECIMAL__
#define __BIG_DECIMAL__
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
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
unsigned long long stringToDecimal(string);
string DecimalTostring(unsigned long long);
string Calculate(string);
int Compare(string, string);
pair<string,string> Fraction(string);
string Trim(string);
#endif