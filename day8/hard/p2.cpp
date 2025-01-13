#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, minutes = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty() && fresh) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d], ny = y + dirs[d + 1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                }
            }
            minutes++;
        }
        return fresh ? -1 : minutes;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << solution.orangesRotting(grid) << endl;
    return 0;
}
