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

#include "BigDecimal.h"

int main()
{	
	string In;

	while (1)
	{
		cout<<": ";
		getline(cin, In);
		if(In=="exit") exit(0);
		cout << "-> "<<Calculate(In) << endl<<endl;
	}
}
