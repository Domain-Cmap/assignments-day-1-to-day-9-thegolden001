#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> board(n, -1);  
        solve(board, 0, n, result);
        return result;
    }
    void solve(vector<int>& board, int row, int n, int& result) {
        if (row == n) {
            result++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row] = col;
                solve(board, row + 1, n, result);
                board[row] = -1;  
            }
        }
    }
    bool isSafe(vector<int>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution solution;
    int n = 4;
    cout << solution.totalNQueens(n) << endl;  
    return 0;
}
