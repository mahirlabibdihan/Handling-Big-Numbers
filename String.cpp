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
	out<<str.s;
	return out;
}

String operator+(char c, String str)
{
	return c+str;
}
String operator+(const char* str1, String str2)
{
	return str2.push_front(str1);
}