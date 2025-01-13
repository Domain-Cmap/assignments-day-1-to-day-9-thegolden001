#include <iostream>
using namespace std;
int rev(int n) {
    int revnum = 0;  
    while (n > 0) {
        revnum = revnum * 10 + n % 10;  
        n /= 10;  
    }
    return revnum;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << rev(n) << endl;  
    return 0;
}
