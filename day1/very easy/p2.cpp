#include <iostream>
using namespace std;

void printOddNumbers(int n) {
    for (int i = 1; i <= n; i += 2) {
        cout << i;
        if (i + 2 <= n) cout << " "; 
    }
    cout << endl;
}

int main() {
    int n;
    cout << "enter num ";
    cin >> n;
    printOddNumbers(n);
    return 0;
}
