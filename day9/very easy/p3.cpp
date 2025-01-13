#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string temp = word;
        while (sequence.find(temp) != string::npos) {
            count++;
            temp += word;
        }
        return count;
    }
};
int main() {
    Solution solution;
    string sequence = "ababc";
    string word = "ab";
    cout << solution.maxRepeating(sequence, word) << endl; // Output: 2
    return 0;
}
