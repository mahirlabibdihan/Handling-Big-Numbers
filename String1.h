#ifndef __STRING__
#define __STRING__
#include <algorithm>
#include <iostream>
#include <string>
#include "CString.h"
using namespace std;
class String :public string
{
public:
	String():string()
	{
		
	}
	String(const char *str):string(str)
	{
		
	}
	String(const String& str):string(str)
	{

	}

	void set(const char *str)
	{
		*this = str;
	}
	string get()
	{
		return *this;
	}
	void set(const String &str)
	{
		*this =  str;
	}

	int length()
	{
		return this->length();
	}

	void reverse()
	{
		std::reverse(this->begin(),this->end());
	}
	void resize(int n)
	{
		string::resize(n+1);
	}
	void push_back(char c)
	{
		*this +=c;
	}
	void push_back(String c)
	{
		*this +=c;
	}
	void push_front(char c)
	{
		*this = c + *this;
	}

	void erase(int idx)
	{
		string::erase(this->begin()+idx);
	}
	void insert(int idx,char c)
	{
		string::insert(this->begin()+idx,c);
	}
	String pop_back()
	{
		string::erase(this->begin()+length() - 1);
		return *this;
	}
	String pop_front()
	{
		if(!this->empty()){
			string::erase(this->begin());
		}
		return *this;
	}
	int compare(String str)
	{
		return this->compare(str);
	}
	char& back()
	{
		return this->back();
	}
	char& front()
	{
		return this->front();
	}
	char charAt(int index)
	{
		return this->at(index);
	}
	bool empty()
	{
		return this->empty();
	}
	char& operator[](int index)
	{
		return this->at(index);
	}
	String operator=(const char* str)
	{
		*this = str;
		return *this;
	}
	String operator=(String str)
	{
		*this = str;
		return *this;
	}
	String operator=(string str)
	{
		*this = str;
		return *this;
	}

	void operator+=(char c)
	{
		*this += c;
	}
	void operator+=(const char* str)
	{
		*this += str;
	}
	void operator+=(String str)
	{
		*this += str;
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
		return *this + c;
	}
	String operator+(const char* str)
	{
		return *this + str;
	}
	String operator+(String str)
	{
		return *this + str;
	}
	
	friend String operator+(char c, String str);
	friend String operator+(const char* c, String str);
	friend istream& operator>>(istream& in, String &str);
	friend ostream& operator<<(ostream& out, String str);
};
#endif