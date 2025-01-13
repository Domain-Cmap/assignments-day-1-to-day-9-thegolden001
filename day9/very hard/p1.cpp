#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return max(0, helper(grid, 0, 0, n - 1, n - 1, dp));
    }
private:
    int helper(vector<vector<int>>& grid, int r1, int c1, int r2, int c2, vector<vector<vector<int>>>& dp) {
        if (r1 >= grid.size() || c1 >= grid[0].size() || r2 >= grid.size() || c2 >= grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1;
        
        if (r1 == grid.size() - 1 && c1 == grid[0].size() - 1) {
            return grid[r1][c1] == 1 ? 1 : 0;
        }

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = (r1 == r2 && c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
        
        int maxCherries = max({helper(grid, r1 + 1, c1, r2 + 1, c2, dp),
                               helper(grid, r1 + 1, c1, r2, c2 - 1, dp),
                               helper(grid, r1, c1 + 1, r2 + 1, c2, dp),
                               helper(grid, r1, c1 + 1, r2, c2 - 1, dp)});
        
        dp[r1][c1][r2] = cherries + maxCherries;
        
        return dp[r1][c1][r2];
    }
};
int main() {
    Solution solution;
    vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    cout << solution.cherryPickup(grid) << endl; 
    return 0;
}
