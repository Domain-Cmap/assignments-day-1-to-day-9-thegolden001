#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n + 1, 1e9);  
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > dist[node]) continue;
            for (auto& neighbor : graph[node]) {
                int nextNode = neighbor.first, time = neighbor.second;
                if (dist[node] + time < dist[nextNode]) {
                    dist[nextNode] = dist[node] + time;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int maxDist = *max_element(dist.begin() + 1, dist.end());
        return maxDist == 1e9 ? -1 : maxDist;  
    }
};
int main() {
    Solution solution;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout << solution.networkDelayTime(times, n, k) << endl;
    return 0;
}
