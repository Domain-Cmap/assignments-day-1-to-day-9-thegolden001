#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int rootCount(int n, vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> guessCount(n, 0);
        for (const auto& guess : guesses) {
            guessCount[guess[1]]++;
        }
        
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            int validGuesses = 0;
            for (const auto& guess : guesses) {
                if (guess[0] == i || guess[1] == i) {
                    validGuesses++;
                }
            }
            if (validGuesses >= k) {
                result++;
            }
        }

        return result;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{4,2}};
    vector<vector<int>> guesses = {{1,3},{0,1},{1,0},{2,4}};
    int k = 3;
    cout << solution.rootCount(5, edges, guesses, k) << endl;
    return 0;
}
