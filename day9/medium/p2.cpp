#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void generateParenthesesHelper(int open, int close, int n, string current, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        if (open < n) {
            generateParenthesesHelper(open + 1, close, n, current + "(", result);
        }

        if (close < open) {
            generateParenthesesHelper(open, close + 1, n, current + ")", result);
        }
    }
    vector<string> generateParentheses(int n) {
        vector<string> result;
        generateParenthesesHelper(0, 0, n, "", result);
        return result;
    }
};
int main() {
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParentheses(n);

    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl; 
    return 0;
}
