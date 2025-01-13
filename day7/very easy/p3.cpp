#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void findPaths(int x, int y, int n, string path, vector<string>& result) {
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }
        
        if (x < n - 1) {
            findPaths(x + 1, y, n, path + "D", result);
        }
        if (y < n - 1) {
            findPaths(x, y + 1, n, path + "R", result);
        }
    }
    vector<string> getAllPaths(int n) {
        vector<string> result;
        findPaths(0, 0, n, "", result);
        return result;
    }
};
int main() {
    Solution solution;
    int n = 2;
    vector<string> paths = solution.getAllPaths(n);
    
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
