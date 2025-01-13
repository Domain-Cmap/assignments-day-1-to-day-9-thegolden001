#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool insideCircle(int x, int y, int cx, int cy, int r) {
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
}
int maxDarts(vector<vector<int>>& darts, int r) {
    int n = darts.size();
    int max_darts = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = darts[i][0], y1 = darts[i][1];
            int x2 = darts[j][0], y2 = darts[j][1];
            int dist_squared = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            if (dist_squared > 4 * r * r) continue;

            double mid_x = (x1 + x2) / 2.0;
            double mid_y = (y1 + y2) / 2.0;
            int count = 0;
            for (int k = 0; k < n; k++) {
                int x = darts[k][0], y = darts[k][1];
                if (insideCircle(x, y, mid_x, mid_y, r)) {
                    count++;
                }
            }
            max_darts = max(max_darts, count);
        }
    }

    return max_darts;
}
int main() {
    vector<vector<int>> darts = {{-2,0},{2,0},{0,2},{0,-2}};
    int r = 2;
    cout << "Max darts inside circle: " << maxDarts(darts, r) << endl;
    return 0;
}
