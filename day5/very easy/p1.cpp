#include <iostream>
#include <vector>
using namespace std;
int search(const vector<int>& arr, int k) {
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        if (arr[i] == k) {
            return i + 1; 
        }
    }
    return -1;
}
int main() {
    int k, n;
    cin >> k >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int result = search(arr, k);
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at position " << result << endl;
    }
    return 0;
}