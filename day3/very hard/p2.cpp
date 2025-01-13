#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long modExp(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
int maxNiceDivisors(int primeFactors) {
    if (primeFactors <= 3) return primeFactors;

    int q = primeFactors / 3;
    int r = primeFactors % 3;

    if (r == 0) {
        return modExp(3, q, MOD);
    } else if (r == 1) {
        return (modExp(3, q - 1, MOD) * 4) % MOD;
    } else { // r == 2
        return (modExp(3, q, MOD) * 2) % MOD;
    }
}
int main() {
    cout << maxNiceDivisors(5) << endl;  
    cout << maxNiceDivisors(8) << endl;  
    return 0;
}
