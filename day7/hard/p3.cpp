#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < (1 << n); ++i) {
            result.push_back(i ^ (i >> 1));  
        }
        return result;
    }
};
int main() {
    Solution solution;
    int n = 2;
    vector<int> result = solution.grayCode(n);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
