#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool evaluateExpression(string expression) {
    stack<char> stk;

    for (char ch : expression) {
        if (ch == ')') {
            string subExpr = "";
            while (!stk.empty() && stk.top() != '(') {
                subExpr = stk.top() + subExpr;
                stk.pop();
            }
            stk.pop(); 

            char op = stk.top();
            stk.pop();

            bool result = (op == '|') ? false : true;
            for (char c : subExpr) {
                if (op == '|') result |= (c == 't');
                else if (op == '&') result &= (c == 't');
            }
            stk.push(result ? 't' : 'f');
        } else if (ch != ',') {
            stk.push(ch);
        }
    }

    return stk.top() == 't';
}
int main() {
    cout << boolalpha << evaluateExpression("&(|(f))") << endl;   
    cout << boolalpha << evaluateExpression("|(f,f,f,t)") << endl; 
    cout << boolalpha << evaluateExpression("!(&(f,t))") << endl; 
    return 0;
}
