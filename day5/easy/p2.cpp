#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sortedSquares(const vector<int>& nums) {
    int n = nums.size();
    vector<int> squares(n);
    int left = 0, right = n - 1;
    int i = n - 1;
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare >= rightSquare) {
            squares[i--] = leftSquare;
            left++;
        } else {
            squares[i--] = rightSquare;
            right--;
        }
    }
    return squares;
}
int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);
    cout << "Squares of the sorted array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}