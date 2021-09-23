#include "BigDecimal.h"
BigDecimal BigDecimal::mul(BigDecimal a)
{
	this->trim();
	a.trim();
	if (a == "0" || (*this)=="0") return "0";
	bool negative = false;
	if ( this->charAt(0) == '-'  && a.charAt(0) == '-')
	{
		this->pop_front();
		a.pop_front();	
	}

	else if (a[0] == '-')
	{
		negative = true;
		a.pop_front();
	}

	else if (this->charAt(0) == '-')
	{
		negative = true;
		this->pop_front();
	}

	BigDecimal num1, num2, multiplication;
	if (a.length() == 0) a.set("0");
	if (this->length() == 0) this->set("0");
	int i, j, n = a.length(), m = this->length(), p = 0, q = 0;

	for (i = 0; i < n; i++)
	{
		if (a[i] != '.')
		{
			num1 += a[i];
		}
		else
		{
			p = n - 1 - i;
		}
	}

	for (i = 0; i < m; i++)
	{
		if (this->charAt(i) != '.')
		{
			num2 += this->charAt(i);
		}
		else
		{
			q = m - 1 - i;
		}
	}

	num1.reverse();
	num2.reverse();

	n = num1.length();
	m = num2.length();

	for (i = 0; i < m+n ; i++)
	{
		multiplication += '0';
		// cout<<multiplication<<endl;
	}
	// cout<<m+n<<" "<<a<<endl;
	//cout<<num1<<" "<<num2<<endl;

	int Carry;
	for (i = 0; i < n; i++)
	{
		Carry = 0;
		int temp1 = num1[i] - 48;

		for (j = 0; j < m; j++)
		{
			// cout<<".";
			int temp2 = num2[j] - 48;

			int temp = temp1 * temp2 + multiplication[i + j] + Carry - 48;

			multiplication[i + j] = (temp % 10) + 48;

			Carry = temp / 10;
		}

		if (Carry) {
			multiplication[i + j] += Carry;
		}

	}
	// if (Carry) multiplication[ m + n-1] += Carry;

	
	while (multiplication.length() > 0 && multiplication.back() == '0') {

		multiplication.pop_back();
	}



	n = multiplication.length();

	if (p + q > 0)
	{
		if (p + q > n)
		{
			for (i = n; i < p + q; i++)
			{
				multiplication += '0';
			}
		}


		multiplication.insert(p + q, '.');
		multiplication.reverse();
		multiplication.trim();
	}

	else
	{
		multiplication.reverse();
	}

	if (multiplication.length() > 0) {
		return (negative ? "-" : "") + multiplication;
	}
	else{
		return "0";
	}
}
