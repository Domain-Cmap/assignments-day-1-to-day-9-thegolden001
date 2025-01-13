#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int racecar(int target) {
        unordered_map<int, int> visited;
        queue<pair<int, int>> q; 
        q.push({0, 1});
        visited[0] = 1;
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [pos, speed] = q.front();
                q.pop();
                if (pos == target) return steps;
                int newPos = pos + speed;
                int newSpeed = speed * 2;
                if (visited.find(newPos) == visited.end()) {
                    visited[newPos] = newSpeed;
                    q.push({newPos, newSpeed});
                }
                int reverseSpeed = (speed > 0) ? -1 : 1;
                if (visited.find(pos) == visited.end()) {
                    visited[pos] = reverseSpeed;
                    q.push({pos, reverseSpeed});
                }
            }
            steps++;
        }
        return -1;
    }
};
int main() {
    Solution solution;
    int target = 6;
    cout << solution.racecar(target) << endl; 
    return 0;
}
