#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;

        for (int i = 0; i < n; ++i) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << solution.canJump(nums) << endl; 
    return 0;
}
