#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> bfsOfGraph(int n, vector<vector<int>>& adj) {
    vector<int> result;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}
int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> result = bfsOfGraph(5, adj);
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl; 
    return 0;
}
