#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int componentCount = 0;
        function<int(int, int)> dfs = [&](int node, int parent) {
            int subtreeSum = values[node];
            
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    subtreeSum += dfs(neighbor, node);
                }
            }
            
            if (subtreeSum % k == 0) {
                componentCount++;
                subtreeSum = 0;
            }
            return subtreeSum;
        };

        dfs(0, -1);
        
        return componentCount;
    }
};
int main() {
    Solution solution;
    int n = 5;
    vector<vector<int>> edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> values = {1, 8, 1, 4, 4};
    int k = 6;
    cout << solution.maxKDivisibleComponents(n, edges, values, k) << endl;
    return 0;
}
