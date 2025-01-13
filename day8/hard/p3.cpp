#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0)), atlantic(m, vector<int>(n, 0)), result;
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j) {
        if (ocean[i][j]) return;
        ocean[i][j] = 1;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d], nj = j + dirs[d + 1];
            if (ni >= 0 && ni < heights.size() && nj >= 0 && nj < heights[0].size() && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, ocean, ni, nj);
            }
        }
    }
};
int main() {
    Solution solution;
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> result = solution.pacificAtlantic(heights);
    for (auto& cell : result) {
        cout << "[" << cell[0] << "," << cell[1] << "] ";
    }
    cout << endl;
    return 0;
}
