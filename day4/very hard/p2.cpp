#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> gcdPairsQueries(vector<int>& nums, vector<int>& queries) {
    vector<int> gcdPairs;
    
    // Calculate t
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            gcdPairs.push_back(gcd(nums[i], nums[j]));
        }
    }

    // Sort the GCD pairs in ascending order
    sort(gcdPairs.begin(), gcdPairs.end());

    // Answer the queries
    vector<int> answer;
    for (int query : queries) {
        answer.push_back(gcdPairs[query]);
    }

    return answer;
}

int main() {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cin >> q;
    vector<int> queries(q);
    
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    vector<int> result = gcdPairsQueries(nums, queries);
    
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
