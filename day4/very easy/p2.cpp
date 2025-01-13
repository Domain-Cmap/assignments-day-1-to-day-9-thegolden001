#include <iostream>
#include <unordered_map>
using namespace std;
int firstUniqChar(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}
int main() {
    string s1 = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";

    cout << firstUniqChar(s1) << endl;
    cout << firstUniqChar(s2) << endl;
    cout << firstUniqChar(s3) << endl;

    return 0;
}
