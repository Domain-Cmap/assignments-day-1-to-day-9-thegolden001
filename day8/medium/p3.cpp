#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
    if (index == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) return false;
    char temp = board[i][j];
    board[i][j] = '#';
    bool found = dfs(board, word, i + 1, j, index + 1) ||
                 dfs(board, word, i - 1, j, index + 1) ||
                 dfs(board, word, i, j + 1, index + 1) ||
                 dfs(board, word, i, j - 1, index + 1);
    board[i][j] = temp;
    return found;
}
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (dfs(board, word, i, j, 0)) return true;
        }
    }
    return false;
}
int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    if (exist(board, word)) {
        cout << "Word found" << endl;
    } else {
        cout << "Word not found" << endl;
    }
    return 0;
}
