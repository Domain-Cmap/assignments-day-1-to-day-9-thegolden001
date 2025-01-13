#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] != node) parent[node] = findParent(parent[node], parent);
        return parent[node];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int parentU = findParent(u, parent), parentV = findParent(v, parent);
            if (parentU == parentV) return edge;
            parent[parentU] = parentV;
        }
        return {};
    }
};
int main() {
    Solution solution;
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> result = solution.findRedundantConnection(edges);
    for (int val : result) cout << val << " ";
    cout << endl;
    return 0;
}
