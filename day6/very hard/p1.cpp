#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countPalindromePaths(vector<int>& parent, string& s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
        
        unordered_map<int, int> pathCount;
        pathCount[0] = 1;
        int result = 0;

        function<void(int, int)> dfs = [&](int node, int bitmask) {
            result += pathCount[bitmask];
            
            for (int i = 0; i < 26; ++i) {
                if (pathCount.find(bitmask ^ (1 << i)) != pathCount.end()) {
                    result += pathCount[bitmask ^ (1 << i)];
                }
            }
            
            pathCount[bitmask]++;
            
            for (int child : children[node]) {
                dfs(child, bitmask ^ (1 << (s[child] - 'a')));
            }
            
            pathCount[bitmask]--;
        };

        dfs(0, 0);

        return result;
    }
};
int main() {
    Solution solution;
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "acaabc";
    cout << solution.countPalindromePaths(parent, s) << endl;
    return 0;
}
