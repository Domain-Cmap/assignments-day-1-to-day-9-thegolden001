#include <iostream>
using namespace std;

int largestDigit(int n) {
    int maxDigit = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        n /= 10;
    }
    return maxDigit;
}

int main() {
    int n;
    cin >> n;
    cout << largestDigit(n) << endl;
    return 0;
}
