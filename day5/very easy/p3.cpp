#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> indices;
    int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (left <= right) {
        for (int i = left; i <= right; ++i) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    vector<int> result = targetIndices(nums, target);
    cout << "Target indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}