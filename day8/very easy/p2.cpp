#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
        for (const auto& t : trust) {
            outDegree[t[0]]++;
            inDegree[t[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    int n = 3;
    cout << "Town Judge: " << sol.findJudge(n, trust) << endl; // Output: 3
    return 0;
}
