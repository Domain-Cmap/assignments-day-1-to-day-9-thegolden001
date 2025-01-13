#include <iostream>
#include <vector>
using namespace std;
vector<int> findCommonElements(const vector<int>& arr1, const vector<int>& arr2, const vector<int>& arr3) {
    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
    int i = 0, j = 0, k = 0;
    vector<int> result;
    while (i < n1 && j < n2 && k < n3) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            result.push_back(arr1[i]);
            
            while (i + 1 < n1 && arr1[i] == arr1[i + 1]) {
                i++;
            }
            while (j + 1 < n2 && arr2[j] == arr2[j + 1]) {
                j++;
            }
            while (k + 1 < n3 && arr3[k] == arr3[k + 1]) {
                k++;
            }
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    if (result.empty()) {
        return {-1}; 
    }
    return result;
}
int main() {
    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};
    vector<int> common = findCommonElements(arr1, arr2, arr3);
    if (common[0] == -1) {
        cout << "No common elements" << endl;
    } else {
        cout << "Common elements: ";
        for (int num : common) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}