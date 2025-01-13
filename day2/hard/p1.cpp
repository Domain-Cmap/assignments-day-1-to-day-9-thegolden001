#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxHappyGroups(int batchSize, vector<int>& groups) {
    sort(groups.rbegin(), groups.rend());  
    int happyGroups = 0, remaining = 0;

    for (int group : groups) {
        if (group <= batchSize - remaining) {
            happyGroups++;
            remaining = group;
        } else {
            remaining += group % batchSize;
        }
    }
    return happyGroups;
}
int main() {
    int batchSize = 3;
    vector<int> groups = {1, 2, 3, 4, 5, 6};
    cout << "Max Happy Groups: " << maxHappyGroups(batchSize, groups) << endl;
    return 0;
}
