#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
int main() {
    Solution solution;
    int n = 2;
    cout << solution.divisorGame(n) << endl; 
    return 0;
}
