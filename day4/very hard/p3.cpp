#include <iostream>
#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int max_len = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                max_len = max(max_len, i - stk.top());
            }
        }
    }
    
    return max_len;
}

int main() {
    string s;
    cin >> s;
    cout << longestValidParentheses(s) << endl;
    return 0;
}
