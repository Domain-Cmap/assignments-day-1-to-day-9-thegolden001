#include <iostream>
using namespace std;
int eliminationGame(int n) {
    bool leftToRight = true;
    while (n > 1) {
        if (leftToRight) {
            n = n / 2;
        } else {
            n = (n + 1) / 2;
        }
        leftToRight = !leftToRight;
    }
    return n;
}
int main() {
    int n = 9;
    cout << eliminationGame(n) << endl; 
    n = 1;
    cout << eliminationGame(n) << endl; 
    return 0;
}
