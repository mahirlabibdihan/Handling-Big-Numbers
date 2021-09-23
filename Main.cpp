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
	BigDecimal bd, cd;
	bd.set("100");
	// cd.set("3314240134565353266999387579130131288000666286242049487118846032383059131291716864129885722968716753156177920000000000000000000");

	// bd.out();
	// cout << bd.add(cd) << endl;
	// cout << bd.sub(cd) << endl;
	// cout << bd.mul(cd) << endl;
	// cout << bd.div(cd) << endl; 
	cout << bd.factorial() << endl;
	// cout << bd.compareTo(cd) << endl;
}