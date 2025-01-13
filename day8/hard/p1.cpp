#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent, owner;
        unordered_map<string, unordered_set<string>> unions;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                parent[account[i]] = account[i];
                owner[account[i]] = account[0];
            }
        }
        for (auto& account : accounts) {
            string p = find(account[1], parent);
            for (int i = 2; i < account.size(); ++i) {
                parent[find(account[i], parent)] = p;
            }
        }
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                unions[find(account[i], parent)].insert(account[i]);
            }
        }
        vector<vector<string>> result;
        for (auto& group : unions) {
            vector<string> emails(group.second.begin(), group.second.end());
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), owner[group.first]);
            result.push_back(emails);
        }
        return result;
    }
    
    string find(string s, unordered_map<string, string>& parent) {
        return parent[s] == s ? s : find(parent[s], parent);
    }
};
int main() {
    Solution solution;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    vector<vector<string>> result = solution.accountsMerge(accounts);
    for (auto& account : result) {
        for (auto& email : account) cout << email << " ";
        cout << endl;
    }
    return 0;
}
