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

#include <map>
#include <stack>
#include "BigDecimal.h"

// Tree Structure
class Node
{
public:
    string data;
    Node *left, *right;
    Node(string str = nullptr) {
        data = str;
        left = right = nullptr;
    }

    void operate(stack<Node*> &stN, stack<string> &stC)
    {
        Node *t, *t1, *t2;
        // Get and remove the top element
        // from the character stack
        t = new Node(stC.top());
        stC.pop();

        // Get and remove the top element
        // from the Node stack
        t1 = stN.top();
        stN.pop();

        // Get and remove the currently top
        // element from the Node stack
        t2 = stN.top();
        stN.pop();

        // Update the tree
        t->left = t2;
        t->right = t1;

        // Push the Node to the Node stack
        stN.push(t);
    }

    // Function to build Expression Tree
    void build(string s)
    {
        // stack to hold nodes
        stack<Node*> stN;

        // stack to hold chars
        stack<string> stC;

        // Prioritising the operators
        map<char, int> operators;
        operators['+'] = operators['-'] = 1;
        operators['/'] = operators['*'] = operators['%'] = 2;
        operators['^'] = 3;
        operators[')'] = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]==' ') continue;

            // Push '(' in char stack
            else if (s[i] == '(') {
                stC.push(string(1, s[i]));
            }

            // Push the numbers in Node stack
            else if (isdigit(s[i]) || s[i] == '.')
            {
                string num;
                while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
                    num += s[i];
                    i++;
                }

                stN.push(new Node(num));
                i--;
            }

            // Evaluate whole expression from '(' to ')'
            else if (s[i] == ')') {
                while (!stC.empty() && stC.top() != "(")
                {
                    operate(stN, stC);
                }
                if (!stC.empty()) stC.pop();
            }

            // Push operators in char stack
            else if (operators.find(s[i])!=operators.end())
            {
                // If an operator with lower or
                // same associativity appears
                while ( !stC.empty() && stC.top() != "(" && operators[stC.top()[0]] >= operators[s[i]] )
                {
                    if (s[i] == '^') {
                        if (operators[stC.top()[0]] >  operators[s[i]]) {   // Associativity: Right to Left
                            operate(stN, stC);
                        }
                    }
                    else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                        if (operators[stC.top()[0]] >= operators[s[i]]) {   // Associativity: Left to Right
                            operate(stN, stC);
                        }
                    }
                }

                // Push s[i] to char stack
                stC.push(string(1, s[i]));
            }
        }

        // Least Precedence operations are left
        while (!stC.empty())
        {
            operate(stN, stC);
        }
        this->data = stN.top()->data;
        this->left = stN.top()->left;
        this->right = stN.top()->right;
    }
};
BigDecimal evaluate(Node* root) {
    BigDecimal x, y, z;
    try {
    	stod(root->data);
    	cout<<root->data<<endl;
        return BigDecimal(root->data);
    }
    catch (exception &e) {
        x = evaluate(root->left);
        y = evaluate(root->right);
        if (root->data == "+") {
            z = x.add(y);
        }
        else if (root->data == "-") {
            z = x.sub(y);
        }
        else if (root->data == "*") {
            z = x.mul(y);
        }
        else if (root->data == "/") {
            z = x.div(y);
        }
        else if (root->data == "%") {
            z = x.mod(y);
        }
        else if (root->data == "^") {
            z = x.pow(y);
        }
        return z;
    } 
    return root->data;
}
int main()
{
	cout<<"Equation: ";
    string s;
    cin >> s;
    Node* root = new Node(s);
    root-> build(s);
    cout << "Result: "<<evaluate(root) << endl;
    return 0;
}