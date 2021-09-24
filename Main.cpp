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

/	      -> Divide
	
%	      -> Modulas
    
^	      -> Power

!	      -> Factorial

&	      -> And
	
|	      -> Or

p         -> nPr

c         -> nCr

LCM()     -> LCM

GCD()     -> GCD

sin()
csc()   
cos()
sec()
tan()
cot()
aSin()
aCsc()
aCos()
aSec()
aTan()
aCot()


exit ->  Exit
###########################

*/

#include "ExpressionTree.h"
#include "BigDecimal.h"

BigDecimal evaluate(ExpressionTree* root) {
    BigDecimal x, y, z;
    try{
    	stod(root->data);
        return BigDecimal(root->data);
    }
    catch (exception &e) {
        x = evaluate(root->left);
        y = evaluate(root->right);
        if (root->data == "+") {
            z = x + y;
        }
        else if (root->data == "-") {

            z = x - y;
        }
        else if (root->data == "*") {
            z = x * y;
        }
        else if (root->data == "/") {
            z = x / y;
        }
        else if (root->data == "%") {
            z = x % y;
        }
        else if (root->data == "^") {
            z = x ^ y;
        }
        return z;
    } 
    return root->data;
}

void validateExpression(string &s){
    for(int i=0;i<s.length()-1;i++){
            if(isdigit(s[i])&&s[i+1]=='('){
                s.insert(s.begin()+i+1,'*');
            }
            else if(s[i]=='('&&s[i+1]=='-'){
                 s.insert(s.begin()+i+1,'0');
            }
        }
    s = "(" + s + ")";
}
int main()
{
    while(true){
        cout<<"Equation ( Using 0-9,.,+,-,/,*,(,),^ ): ";
        string s;
        cin >> s;   // Taking expression as input
        validateExpression(s);  // Validating expression
        ExpressionTree* root = new ExpressionTree(s);   
        root-> build(s);    // Building expression tree
        cout << "Result: "<<evaluate(root) << endl;  // Calculating result
    }

    // BigDecimal a("10"),b("16");
    // cout<<fromDecimal(a,b)<<endl;
    return 0;
	
}