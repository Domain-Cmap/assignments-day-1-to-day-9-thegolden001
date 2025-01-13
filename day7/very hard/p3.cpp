#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            if (c == ')') balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        vector<string> result;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        
        bool found = false;
        
        while (!q.empty()) {
            int size = q.size();
            vector<string> level;
            
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();
                
                if (isValid(current)) {
                    result.push_back(current);
                    found = true;
                }
                
                if (found) continue;
                for (int j = 0; j < current.size(); j++) {
                    if (current[j] != '(' && current[j] != ')') continue;
                    string next = current.substr(0, j) + current.substr(j + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        level.push_back(next);
                    }
                }
            }
            if (found) break;
            for (const string& next : level) {
                q.push(next);
            }
        }
        
        return result;
    }
};
int main() {
    Solution sol;
    string s = "()())()";
    vector<string> res = sol.removeInvalidParentheses(s);
    for (const string& str : res) {
        cout << str << endl;
    }
    return 0;
}
