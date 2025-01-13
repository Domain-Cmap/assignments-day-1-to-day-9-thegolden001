#include <iostream>
#include <vector>
using namespace std;
char findKthCharacter(long long k, vector<int>& operations) {
    long long length = 1; 
    vector<long long> lengths;
    for (int op : operations) {
        if (op == 0) {
            length *= 2;
        } else {
            length *= 2;
        }
        lengths.push_back(length);
        if (length >= k) break;
    }
    for (int i = operations.size() - 1; i >= 0; --i) {
        if (operations[i] == 0) {
            if (k > lengths[i] / 2) {
                k -= lengths[i] / 2;
            }
        } else { 
            if (k > lengths[i] / 2) {
                k -= lengths[i] / 2;
                k = (k - 1) % 26 + 1; 
            }
        }
    }
    return 'a' + k - 1;
}
int main() {
    vector<int> operations1 = {0, 0, 0};
    cout << findKthCharacter(5, operations1) << endl; 

    vector<int> operations2 = {0, 1, 0, 1};
    cout << findKthCharacter(10, operations2) << endl; 

    return 0;
}
