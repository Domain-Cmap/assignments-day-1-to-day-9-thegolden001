#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void findCombinations(int n, int target, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0 && current.size() == n) {
            result.push_back(current);
            return;
        }
        if (current.size() == n || target <= 0) {
            return;
        }

        for (int i = 1; i <= 6; ++i) {
            current.push_back(i);
            findCombinations(n, target - i, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> diceRollCombinations(int n, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(n, target, current, result);
        return result;
    }
};
int main() {
    Solution solution;
    int n = 2, target = 5;
    vector<vector<int>> combinations = solution.diceRollCombinations(n, target);
    
    for (auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
