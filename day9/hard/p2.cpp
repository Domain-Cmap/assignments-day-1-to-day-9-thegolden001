#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int minHealth = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = (minHealth <= 0) ? 1 : minHealth;
            }
        }

        return dp[0][0];
    }
};
int main() {
    Solution solution;
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << solution.calculateMinimumHP(dungeon) << endl; 
    return 0;
}
