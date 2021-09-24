#ifndef __STRING__
#define __STRING__
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class String // :public String
{
protected:
	string s;
public:
	String()
	{
		s = "";
	}
	String(const char *str)
	{
		s = str;
	}
	String(const String& str)
	{
		s = str.s;
	}

	void set(const char *str)
	{
		s = str;
	}
	string get()
	{
		return s;
	}
	void set(const String &str)
	{
		s =  str.s;
	}

	int length()
	{
		return s.length();
	}

	void reverse()
	{
		std::reverse(s.begin(),s.end());
	}
	void resize(int n)
	{
		s.resize(n+1);;
	}
	void push_back(char c)
	{
		s+=c;
	}
	void push_back(String c)
	{
		s += c.s;
	}
	void push_front(char c)
	{
		s = c + s;
	}

	String push_front(const char* c)
	{	
		s = c + s;
		return *this;
	}

	void erase(int idx)
	{
		s.erase(idx);
	}
	void insert(int idx,char c)
	{
		s.insert(s.begin()+idx,c);
	}
	String pop_back()
	{
		s.erase(length() - 1);
		return *this;
	}
	String pop_front()
	{
		if(!s.empty()){
			s.erase(s.begin());
		}
		return *this;
	}
	int compare(String str)
	{
		return s.compare(str.s);
	}
	char& back()
	{
		return s[length() - 1];
	}
	char& front()
	{
		return s[0];
	}
	char charAt(int index)
	{
		return s[index];
	}
	bool empty()
	{
		return s.empty();
	}
	char& operator[](int index)
	{
		return s[index];
	}
	String operator=(const char* str)
	{
		s = str;
		return *this;
	}
	String operator=(String str)
	{
		s = str.s;
		return *this;
	}

	String operator=(string str)
	{
		this->s = str;
		// cout<<*this<<endl;
		return *this;
	}

	void operator+=(char c)
	{
		s += c;
	}
	void operator+=(const char* str)
	{
		s += str;
	}
	void operator+=(String str)
	{
		s += str.s;
	}
	void operator--()
	{
		pop_back();
	}
	void operator--(int)
	{
		pop_back();
	}
	String operator+(char c)
	{
		String temp;
		temp.s = s + c;
		return temp;
	}
	String operator+(const char* str)
	{
		String temp;
		temp.s = s + str;
		return temp;
	}
	String operator+(String str)
	{
		String temp;
		temp.s = s + str.s;
		return temp;
	}
	bool operator==(String str)
	{
		return s == str.s;
	}
	
	friend String operator+(char c, String str);
	friend String operator+(const char* c, String str);
	friend istream& operator>>(istream& in, String &str);
	friend ostream& operator<<(ostream& out, String str);
};
#endif