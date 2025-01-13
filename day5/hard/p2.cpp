#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class PriorityQueueItem {
public:
    int sum;
    vector<int> indices;

    PriorityQueueItem(int sum, const vector<int>& indices) : sum(sum), indices(indices) {}

    bool operator<(const PriorityQueueItem& other) const {
        return sum > other.sum; 
    }
};
int kthSmallestSum(const vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    priority_queue<PriorityQueueItem> pq;
    for (int i = 0; i < m; ++i) {
        pq.push(PriorityQueueItem(mat[i][0], {i, 0}));
    }
    for (int i = 0; i < k - 1; ++i) {
        PriorityQueueItem current = pq.top();
        pq.pop();
    }
    return pq.top().sum;
}
int main() {
    vector<vector<int>> mat = {{1, 3, 11}, {2, 4, 6}};
    int k = 5;
    int result = kthSmallestSum(mat, k);
    cout << "Kth smallest sum: " << result << endl;
    return 0;
}