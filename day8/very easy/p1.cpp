#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
    }
};
int main() {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    cout << "Center of the star graph: " << sol.findCenter(edges) << endl; // Output: 2
    return 0;
}
