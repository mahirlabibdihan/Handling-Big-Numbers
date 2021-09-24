#include <map>
#include <stack>
#include <string>
using namespace std;
// Tree Structure
class ExpressionTree
{
public:
    string data;
    ExpressionTree *left, *right;
    ExpressionTree(string str = nullptr) {
        data = str;
        left = right = nullptr;
    }

    void operate(stack<ExpressionTree*> &stN, stack<string> &stC)
    {
        ExpressionTree *t, *t1, *t2;
        // Get and remove the top element
        // from the character stack
        t = new ExpressionTree(stC.top());
        stC.pop();

        // Get and remove the top element
        // from the ExpressionTree stack
        t1 = stN.top();
        stN.pop();

        // Get and remove the currently top
        // element from the ExpressionTree stack
        t2 = stN.top();
        stN.pop();

        // Update the tree
        t->left = t2;
        t->right = t1;

        // Push the ExpressionTree to the ExpressionTree stack
        stN.push(t);
    }

    // Function to build Expression Tree
    void build(string s)
    {
        // stack to hold nodes
        stack<ExpressionTree*> stN;

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

            // Push the numbers in ExpressionTree stack
            else if (isdigit(s[i]) || s[i] == '.')
            {
                string num;
                while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
                    num += s[i];
                    i++;
                }

                stN.push(new ExpressionTree(num));
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