#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> target = {1, 2, 3, 4, 5, 0};
        vector<int> start = {board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2]};
        
        if (start == target) return 0;

        unordered_map<string, bool> visited;
        visited[to_string(start)] = true;

        queue<pair<vector<int>, int>> q;
        q.push({start, 0});

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> positions = {{0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {0, 0}};

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            vector<int> state = front.first;
            int step = front.second;
            
            int zeroPos = find(state.begin(), state.end(), 0) - state.begin();

            for (auto& dir : directions) {
                int newPos = zeroPos + dir[0] * 3 + dir[1];
                if (newPos < 0 || newPos >= 6 || (newPos % 3 == 0 && dir[1] == -1) || (newPos % 3 == 2 && dir[1] == 1)) continue;
                
                swap(state[zeroPos], state[newPos]);

                if (state == target) return step + 1;

                if (visited[to_string(state)]) continue;

                visited[to_string(state)] = true;
                q.push({state, step + 1});
                swap(state[zeroPos], state[newPos]);
            }
        }
        
        return -1;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    cout << solution.slidingPuzzle(board) << endl; 
    return 0;
}
