#include <vector>
#include <iostream>
using namespace std;
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  
    }
    return result;
}
int main() {
    vector<int> nums1 = {2, 2, 1};
    cout << singleNumber(nums1) << endl;  
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << singleNumber(nums2) << endl;  
    vector<int> nums3 = {1};
    cout << singleNumber(nums3) << endl;  
    return 0;
}
