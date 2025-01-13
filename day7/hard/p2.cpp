#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(k, n, 1, combination, result);
        return result;
    }

    void backtrack(int k, int n, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (combination.size() == k && n == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            combination.push_back(i);
            backtrack(k, n - i, i + 1, combination, result);  
            combination.pop_back();
        }
    }
};
int main() {
    Solution solution;
    int k = 3, n = 7;
    vector<vector<int>> result = solution.combinationSum3(k, n);
    for (const vector<int>& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
