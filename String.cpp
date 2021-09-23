#include "String.h"
istream& operator>>(istream& in, String &str)
{
	in >> str.s;
	return in;
}
ostream& operator<<(ostream& out,String str)
{
	// for(int i=0;i<130;i++)	{
	// 	cout<<str.charAt(i);
	// }
	out<<str.s<<endl;
	return out;
}

String operator+(char c, String str)
{
	String temp;
	temp.s = str.s + c;
	return temp;
}
String operator+(const char* str1, String str2)
{
	String temp;
	temp.s = str1 + str2.s;
	return temp;
}