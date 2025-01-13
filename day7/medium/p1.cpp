#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        backtrack(digits, 0, "", result, mapping);
        return result;
    }
    void backtrack(string& digits, int index, string current, vector<string>& result, vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            backtrack(digits, index + 1, current + letter, result, mapping);
        }
    }
};
int main() {
    Solution solution;
    string digits = "23";
    vector<string> result = solution.letterCombinations(digits);
    for (const string& combination : result) {
        cout << combination << endl;
    }
    return 0;
}
