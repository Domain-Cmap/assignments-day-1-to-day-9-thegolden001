#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int MOD = 1e9 + 7;
        int n = instructions.size();
        vector<int> bit(n + 1, 0);
        
        auto update = [&](int idx, int val) {
            while (idx <= n) {
                bit[idx] = (bit[idx] + val) % MOD;
                idx += idx & -idx;
            }
        };
        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res = (res + bit[idx]) % MOD;
                idx -= idx & -idx;
            }
            return res;
        };
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int x = instructions[i];
            result = (result + min(query(x - 1), i - query(x))) % MOD;
            update(x, 1);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> instructions = {1, 5, 6, 2};
    cout << "Total cost: " << sol.createSortedArray(instructions) << endl;  // Output: 1
    return 0;
}
