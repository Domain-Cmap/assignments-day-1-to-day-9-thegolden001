#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                q.push({i, j});
            } else {
                mat[i][j] = m * n;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& dir : directions) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] > mat[x][y] + 1) {
                mat[nx][ny] = mat[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return mat;
}
int main() {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = updateMatrix(mat);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
