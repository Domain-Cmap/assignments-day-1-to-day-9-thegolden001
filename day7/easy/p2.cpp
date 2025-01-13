#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int backtrack(int index, int xor_total, vector<int>& nums) {
        if (index == nums.size()) return xor_total;
        return backtrack(index + 1, xor_total ^ nums[index], nums) + backtrack(index + 1, xor_total, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        return backtrack(0, 0, nums);
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 3};
    cout << solution.subsetXORSum(nums) << endl;
    return 0;
}
