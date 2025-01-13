#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        int start = 0, maxLength = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i < n - length + 1; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j]) {
                    if (length == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }

                    if (dp[i][j] && length > maxLength) {
                        maxLength = length;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
int main() {
    Solution solution;
    string s = "babad";
    cout << solution.longestPalindrome(s) << endl; 
    return 0;
}
