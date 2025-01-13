#include <iostream>
#include <vector>
using namespace std;
bool binarySearch(const vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k) {
            return true;
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    bool found = binarySearch(arr, k);
    if (found) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}