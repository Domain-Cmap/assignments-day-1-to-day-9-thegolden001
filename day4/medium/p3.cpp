#include <iostream>
#include <stack>
#include <string>
using namespace std;
int scoreOfParentheses(string s) {
    stack<int> st;
    int score = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(0); 
        } else {
            int v = st.top();
            st.pop();
            score += max(2 * v, 1); 
        }
    }
    return score;
}
int main() {
    string s = "(()())";
    int result = scoreOfParentheses(s);
    cout << "Score of '" << s << "': " << result << endl; 

    return 0;
}