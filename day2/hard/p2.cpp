#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int cherryPickup(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int dp[cols][cols];
    for (int r1 = 0; r1 < cols; r1++) {
        for (int r2 = 0; r2 < cols; r2++) {
            dp[r1][r2] = grid[0][r1] + grid[0][r2];
            if (r1 == r2) dp[r1][r2] = grid[0][r1];
        }
    }
    for (int i = 1; i < rows; i++) {
        int new_dp[cols][cols];
        for (int r1 = 0; r1 < cols; r1++) {
            for (int r2 = 0; r2 < cols; r2++) {
                new_dp[r1][r2] = INT_MIN;
                for (int move1 : {-1, 0, 1}) {  
                    for (int move2 : {-1, 0, 1}) {  
                        int new_r1 = r1 + move1, new_r2 = r2 + move2;
                        if (new_r1 >= 0 && new_r1 < cols && new_r2 >= 0 && new_r2 < cols) {
                            int cherries = grid[i][new_r1] + grid[i][new_r2];
                            if (new_r1 == new_r2) cherries = grid[i][new_r1];
                            new_dp[new_r1][new_r2] = max(new_dp[new_r1][new_r2], dp[r1][r2] + cherries);
                        }
                    }
                }
            }
        }
        for (int r1 = 0; r1 < cols; r1++) {
            for (int r2 = 0; r2 < cols; r2++) {
                dp[r1][r2] = new_dp[r1][r2];
            }
        }
    }
    int max_cherries = 0;
    for (int r1 = 0; r1 < cols; r1++) {
        for (int r2 = 0; r2 < cols; r2++) {
            max_cherries = max(max_cherries, dp[r1][r2]);
        }
    }
    return max_cherries;
}
int main() {
    vector<vector<int>> grid = {{3,1,1}, {2,5,1}, {1,5,5}, {2,1,1}};
    cout << "Max cherries: " << cherryPickup(grid) << endl;
    return 0;
}
