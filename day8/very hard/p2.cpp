#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path = {0};
        dfs(graph, 0, path, result);
        return result;
    }
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        if (node == graph.size() - 1) {
            result.push_back(path);
            return;
        }
        for (int next : graph[node]) {
            path.push_back(next);
            dfs(graph, next, path, result);
            path.pop_back();
        }
    }
};
int main() {
    Solution solution;
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> result = solution.allPathsSourceTarget(graph);
    for (auto& path : result) {
        for (int node : path) cout << node << " ";
        cout << endl;
    }
    return 0;
}
