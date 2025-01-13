#include <iostream>
using namespace std;
int recur_sum(int n) {
    if (n == 0)
        return 0;
    return n + recur_sum(n - 1);
}
int main() {
    int n;
    cin >> n;
    cout << recur_sum(n) << endl;
    return 0;
}
