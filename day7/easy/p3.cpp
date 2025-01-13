#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int hour = 0; hour < 12; ++hour) {
            for (int minute = 0; minute < 60; ++minute) {
                if (countBits(hour) + countBits(minute) == turnedOn) {
                    result.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
                }
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    int turnedOn = 1;
    vector<string> result = solution.readBinaryWatch(turnedOn);
    for (const string& time : result) {
        cout << time << endl;
    }
    
    return 0;
}
