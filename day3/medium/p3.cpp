#include <iostream>
#include <vector>
using namespace std;
bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = nums[i];
            } else {
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1] >= 0;
}
int main() {
    vector<int> nums1 = {1, 5, 2};
    cout << (predictTheWinner(nums1) ? "true" : "false") << endl; 
    vector<int> nums2 = {1, 5, 233, 7};
    cout << (predictTheWinner(nums2) ? "true" : "false") << endl; 

    return 0;
}
