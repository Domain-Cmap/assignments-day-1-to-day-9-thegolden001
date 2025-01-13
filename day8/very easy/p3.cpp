#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != originalColor || image[sr][sc] == color) {
            return;
        }
        image[sr][sc] = color;
        dfs(image, sr + 1, sc, color, originalColor);
        dfs(image, sr - 1, sc, color, originalColor);
        dfs(image, sr, sc + 1, color, originalColor);
        dfs(image, sr, sc - 1, color, originalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    cout << "Flood filled image:\n";
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    return 0;
}
