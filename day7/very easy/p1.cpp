#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void findPaths(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<pair<int, int>>& path, vector<vector<pair<int, int>>>& allPaths) {
        int n = maze.size();
        int m = maze[0].size();

        if (x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == 0 || visited[x][y]) {
            return;
        }

        if (x == n - 1 && y == m - 1) {
            path.push_back({x, y});
            allPaths.push_back(path);
            path.pop_back();
            return;
        }
        visited[x][y] = true;
        path.push_back({x, y});
        
        findPaths(x + 1, y, maze, visited, path, allPaths);
        findPaths(x - 1, y, maze, visited, path, allPaths);
        findPaths(x, y + 1, maze, visited, path, allPaths);
        findPaths(x, y - 1, maze, visited, path, allPaths);
        
        visited[x][y] = false;
        path.pop_back();
    }
    vector<vector<pair<int, int>>> getAllPaths(vector<vector<int>>& maze) {
        int n = maze.size();
        int m = maze[0].size();
        if (maze[0][0] == 0 || maze[n - 1][m - 1] == 0) {
            return {};
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> path;
        vector<vector<pair<int, int>>> allPaths;
        findPaths(0, 0, maze, visited, path, allPaths);
        return allPaths;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> maze = {{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
    vector<vector<pair<int, int>>> paths = solution.getAllPaths(maze);
    if (paths.empty()) {
        cout << "No path exists!" << endl;
    } else {
        cout << "All Paths:" << endl;
        for (auto& path : paths) {
            for (auto& p : path) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
        }
    }
    return 0;
}
