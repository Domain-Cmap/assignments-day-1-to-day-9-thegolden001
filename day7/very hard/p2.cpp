#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void dfs(string& s, unordered_set<string>& wordDict, int start, string current, vector<string>& result) {
        if (start == s.size()) {
            result.push_back(current.substr(1)); 
            return;
        }
        for (int i = start + 1; i <= s.size(); i++) {
            string word = s.substr(start, i - start);
            if (wordDict.find(word) != wordDict.end()) {
                dfs(s, wordDict, i, current + " " + word, result);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> result;
        dfs(s, wordSet, 0, "", result);
        return result;
    }
};
int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result = sol.wordBreak(s, wordDict);
    for (const string& sentence : result) {
        cout << sentence << endl;
    }
    return 0;
}
