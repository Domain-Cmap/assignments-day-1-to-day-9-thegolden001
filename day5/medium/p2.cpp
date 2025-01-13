#include <iostream>
#include <vector>
using namespace std;
int binarySearch(const vector<int>& nums, int target, bool findFirst) {
    int left = 0, right = nums.size() - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            if (findFirst) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    result[0] = binarySearch(nums, target, true);
    if (result[0] != -1) {
        result[1] = binarySearch(nums, target, false);
    }
    return result;
}
int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    for (int index : result) {
        cout << index << " "; 
    }
    return 0;
}
