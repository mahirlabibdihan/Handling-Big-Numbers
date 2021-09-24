#include "String.h"
class BigDecimal{
	String s;
public:
	BigDecimal(){
		s = "";
	}
	String& getString(){
		return s;
	}
	void setString(String s){
		this->s = s;
	}
	// void setString(string s){
	// 	this->s = s;
	// }
	unsigned long long toInt();
	BigDecimal trim();
	int compareTo(BigDecimal);
	BigDecimal(string);
	BigDecimal(String);
	BigDecimal(const char*);
	BigDecimal(const BigDecimal&);
	bool operator>(BigDecimal);
	bool operator<(BigDecimal);
	bool operator==(BigDecimal);
	bool operator>=(BigDecimal);
	bool operator<=(BigDecimal);
	void setDigit(int idx,int n){
		s[idx] = n+'0';
	}
	int digitAt(int idx){
		return s[idx]-'0';
	}
	int front(){
		return s.front() - '0';
	}
	int back(){
		return s.back() - '0';
	}
	// String Sin(String);
	// String Cos(String);
	// String Tan(String);
	// String Csc(String);
	// String Sec(String);
	// String Cot(String);
	// String ASin(String);
	// String ACos(String);
	// String ATan(String);
	// String ACsc(String);
	// String ASec(String);
	// String ACot(String);
	// String Ceil(String);
	// String Round(String);
	// String Floor(String);
	// String Prime(String);
	BigDecimal factorial();
	//BigDecimal operator+(BigDecimal);
	BigDecimal add(BigDecimal);
	BigDecimal pow(BigDecimal);
	// String NPR(String, String);
	// String NCR(String , String);
	// String GCD(String, String);
	// String LCM(String, String);
	BigDecimal power(BigDecimal);
	// String Remainder(String);
	BigDecimal root(BigDecimal);
	// String Exponent(String);
	BigDecimal div(BigDecimal);
	BigDecimal mul(BigDecimal);
	BigDecimal sub(BigDecimal);
	// String ToDecimal(String, String);
	// String FromDecimal(String, String);
	BigDecimal mod(BigDecimal);
	// String DivDigit(String, String);
	// String Abs(String, String);
	// String Trigonometry(String, String);
	// String And(String, String);
	// String Nand(String, String);
	// String Or(String, String);
	// String Nor(String, String);
	// String Not(String);
	// String Xor(String, String);
	// String XNor(String, String);
	// String Log(String, String);
	unsigned long long BigDecimalToDecimal(BigDecimal Number);
	BigDecimal DecimalToBigDecimal(unsigned long long);
	// String Calculate(String);
	pair<BigDecimal, BigDecimal> fraction();
	friend istream& operator>>(istream& in, BigDecimal &str);
	friend ostream& operator<<(ostream& out, BigDecimal str);
};
