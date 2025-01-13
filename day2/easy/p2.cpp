#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int n) {
    if (n == 0) return 0;
    int k = 1;  
    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            ++k;
        }
    }
    return k;
}
int main() {
    int nums1[] = {1, 1, 2};
    int n1 = 3;
    int k1 = removeDuplicates(nums1, n1);
    cout << "k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; ++i) {
        cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    }
    cout << "]" << endl;
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n2 = 10;
    int k2 = removeDuplicates(nums2, n2);
    cout << "k = " << k2 << ", nums = [";
    for (int i = 0; i < k2; ++i) {
        cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    }
    cout << "]" << endl;
    return 0;
}
