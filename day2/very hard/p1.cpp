#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
bool canAssignJobs(int idx, vector<int>& workers, vector<int>& jobs, int k, int maxTime) {
    if (idx == jobs.size()) return true;
    for (int i = 0; i < k; i++) {
        if (workers[i] + jobs[idx] <= maxTime) {
            workers[i] += jobs[idx];
            if (canAssignJobs(idx + 1, workers, jobs, k, maxTime)) return true;
            workers[i] -= jobs[idx];
        }
        if (workers[i] == 0) break;
    }
    return false;
}
int minimumTime(vector<int>& jobs, int k) {
    int left = *max_element(jobs.begin(), jobs.end()), right = accumulate(jobs.begin(), jobs.end(), 0);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        vector<int> workers(k, 0);
        if (canAssignJobs(0, workers, jobs, k, mid)) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}
int main() {
    cout << minimumTime({3,2,3}, 3) << endl;
    cout << minimumTime({1,2,4,7,8}, 2) << endl;
    return 0;
}
