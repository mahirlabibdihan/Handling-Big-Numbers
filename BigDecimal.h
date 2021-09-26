#ifndef __BIG_DECIMAL__
#define __BIG_DECIMAL__
#include "String.h"
struct Fraction;
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
	bool operator!=(BigDecimal);
	bool operator>=(BigDecimal);
	bool operator<=(BigDecimal);
	String toString(){return s;}
	BigDecimal operator+(BigDecimal b){
		return this->add(b);
	}
	BigDecimal operator-(BigDecimal b){
		return this->sub(b);
	}
	friend BigDecimal operator-(const char* str,BigDecimal b);
	BigDecimal operator*(BigDecimal b){
		return this->mul(b);
	}
	BigDecimal operator/(BigDecimal b){
		return this->div(b);
	}
	friend BigDecimal operator/(const char* str,BigDecimal b);
	BigDecimal operator^(BigDecimal b){
		return this->pow(b);
	}
	BigDecimal operator%(BigDecimal b){
		return this->mod(b);
	}
	BigDecimal operator++(int unused) {
		BigDecimal temp = *this;
		*this = *this + "1";
		return temp;
	}
	BigDecimal operator++() {
		*this = *this + "1";
		return *this;
	}

	BigDecimal& operator+=(BigDecimal b) {
		*this = this->add(b);
		return *this;
	}
	BigDecimal& operator-=(BigDecimal b) {
		*this = this->sub(b);
		return *this;
	}
	BigDecimal& operator*=(BigDecimal b) {
		*this = this->mul(b);
		return *this;
	}
	BigDecimal& operator/=(BigDecimal b) {
		*this = this->div(b);
		return *this;
	}
	BigDecimal& operator^=(BigDecimal b) {
		*this = this->pow(b);
		return *this;
	}
	BigDecimal& operator%=(BigDecimal b) {
		*this = this->mod(b);
		return *this;
	}

	void setDigit(int idx,int n){
		s[idx] = n+'0';
	}
	int digitAt(int idx){
		if (idx < s.length()) return s[idx] - '0';
		else return 0;
	}
	int front(){
		return s.front() - '0';
	}
	int back(){
		return s.back() - '0';
	}
	char getSign() {
		if (s.front() == '-') return '-';
		else return '+';
	}
	bool isDecimalPoint(int idx) {
		if (idx >= s.length()) throw exception("Index out of range");
		return s.charAt(idx) == '.';
	}
	bool isNegative() {
		return s.front() == '-' ;
	}

	void reverse() {
		s.reverse();
	}

	// String Prime(String);
	BigDecimal factorial();
	BigDecimal add(BigDecimal);
	BigDecimal pow(BigDecimal);
	BigDecimal NPR(BigDecimal);
	BigDecimal NCR(BigDecimal);
	friend BigDecimal GCD(BigDecimal, BigDecimal);
	friend BigDecimal LCM(BigDecimal, BigDecimal);
	BigDecimal power(BigDecimal);
	// String Remainder(String);
	BigDecimal root(BigDecimal);
	BigDecimal exponent();
	BigDecimal div(BigDecimal);
	BigDecimal mul(BigDecimal);
	BigDecimal sub(BigDecimal);
	friend BigDecimal toDecimal(BigDecimal, BigDecimal);
	friend BigDecimal fromDecimal(BigDecimal, BigDecimal);
	BigDecimal mod(BigDecimal);
	// String DivDigit(String, String);
	friend BigDecimal abs(BigDecimal);
	// String Trigonometry(String, String);
	BigDecimal operator&(BigDecimal);
	// String Nand(String, String);
	BigDecimal operator|(BigDecimal);
	// String Nor(String, String);
	// String Not(String);
	// String Xor(String, String);
	// String XNor(String, String);
	// String Log(String, String);
	unsigned long long BigDecimalToDecimal(BigDecimal Number);
	BigDecimal DecimalToBigDecimal(unsigned long long);

	// String Calculate(String);
	Fraction fraction();
	friend istream& operator>>(istream& in, BigDecimal &str);
	friend ostream& operator<<(ostream& out, BigDecimal str);
	friend BigDecimal sin(BigDecimal);
	friend BigDecimal cos(BigDecimal);
	friend BigDecimal tan(BigDecimal);
	friend BigDecimal csc(BigDecimal);
	friend BigDecimal sec(BigDecimal);
	friend BigDecimal cot(BigDecimal);
	friend BigDecimal aSin(BigDecimal);
	friend BigDecimal aCos(BigDecimal);
	friend BigDecimal aTan(BigDecimal);
	friend BigDecimal aCsc(BigDecimal);
	friend BigDecimal aSec(BigDecimal);
	friend BigDecimal aCot(BigDecimal);
	friend BigDecimal ceil(BigDecimal);
	friend BigDecimal round(BigDecimal);
	friend BigDecimal floor(BigDecimal);
};
struct Fraction {
	BigDecimal numerator, denominator;
};
#endif