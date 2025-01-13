#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
const int MOD = 1e9 + 7;
long long nCr(long long n, long long r) {
    if (r > n) return 0;
    long long num = 1, denom = 1;
    for (long long i = 1; i <= r; i++) {
        num = num * (n - r + i) % MOD;
        denom = denom * i % MOD;
    }
    long long inv_denom = 1;
    for (long long i = 1; i < MOD - 2; i++) {
        inv_denom = inv_denom * denom % MOD;
    }
    return num * inv_denom % MOD;
}
unordered_map<int, int> primeFactorize(int k) {
    unordered_map<int, int> factors;
    for (int i = 2; i <= sqrt(k); i++) {
        while (k % i == 0) {
            factors[i]++;
            k /= i;
        }
    }
    if (k > 1) factors[k]++;
    return factors;
}
int countWays(int n, int k) {
    if (k == 1) return 1;
    unordered_map<int, int> factors = primeFactorize(k);
    long long result = 1;
    for (auto& factor : factors) {
        int exponent = factor.second;
        result = result * nCr(n + exponent - 1, exponent) % MOD;
    }
    return result;
}

vector<int> waysToMakeArray(vector<vector<int>>& queries) {
    vector<int> result;
    for (auto& query : queries) {
        result.push_back(countWays(query[0], query[1]));
    }
    return result;
}

int main() {
    vector<vector<int>> queries = {{2, 6}, {5, 1}, {73, 660}};
    vector<int> result = waysToMakeArray(queries);
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
